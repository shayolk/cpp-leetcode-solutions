/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

template<typename T>
class BlockingQueue {
    queue<T> q;
    mutex mtx;
    condition_variable cv;
    bool closed = false;
    
public:
    BlockingQueue() {}
    
    void push(T t) {
        unique_lock<mutex> lock(mtx);
        q.push(move(t));
        cv.notify_one();
    }
    
    optional<T> pop() {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this] {
            return !q.empty()|| closed;
        });
        
        if (q.empty() && closed) {
            return nullopt;
        }
        
        T t = move(q.front());
        q.pop();
        return t;
    }
    
    bool empty() {
        unique_lock<mutex> lock(mtx);
        return q.empty();
    }
    
    void close() {
        unique_lock<mutex> lock(mtx);
        closed = true;
        cv.notify_all();
    }
};

class Solution {
    BlockingQueue<string> bq;
    vector<thread> threads;
    vector<string> ans;
    set<string> vis;
    mutex mtx;
    string host;
    int active;

    string getHost(const string& url) {
        size_t start = (url.compare(0, 8, "https://") == 0) ? 8 : 7;
        size_t end = url.find('/', start);
        
        if (end == string::npos) {
            return url.substr(start);
        }
        return url.substr(start, end - start);
    }

    void execute(HtmlParser& htmlParser) {
        while (true) {
            auto url_opt = bq.pop();
            if (!url_opt) break;
            
            string url = *url_opt;
            auto urls = htmlParser.getUrls(url);
            
            vector<string> candidate_urls;
            for (string& u : urls) {
                if (getHost(u) == host) {
                    candidate_urls.push_back(move(u));
                }
            }
            
            vector<string> to_push;
            unique_lock<mutex> lock(mtx);
            --active;
            
            for (string& u : candidate_urls) {
                if (!vis.count(u)) {
                    vis.insert(u);
                    ans.push_back(u);
                    to_push.push_back(u);
                    ++active;
                }
            }

            lock.unlock();
            
            for (string& u : to_push) {
                bq.push(move(u));
            }
            
            if (active == 0) {
                bq.close();
                break;
            }
        }
    }

public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        active = 0;
        host = getHost(startUrl);
        unique_lock<mutex> lock(mtx);
        vis.insert(startUrl);
        ans.push_back(startUrl);
        bq.push(startUrl);
        ++active;
        lock.unlock();
        for (int i = 0; i < 16; ++i) {
            threads.emplace_back(thread([this, &htmlParser] {
                execute(htmlParser);
            }));
        }
        for (auto& t: threads) {
            if (t.joinable()) {
                t.join();
            }
        }
        return ans;
    }
};
