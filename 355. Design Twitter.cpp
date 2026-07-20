class Twitter {
    int timestamp;
    map<int,set<int>> following;
    map<int,set<pair<int,int>>> posts;

public:
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        ++timestamp;
        posts[userId].insert({timestamp, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        ++timestamp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> feed;
        auto extract = [&](int user) {
            for (auto& [time, post]: posts[user]) {
                feed.push({time, post});
                if (feed.size() > 10) {
                    feed.pop();
                }
            }
        };
        extract(userId);
        for (int f: following[userId]) {
            extract(f);
        }
        vector<int> feeed;
        while (!feed.empty()) {
            feeed.push_back(feed.top().second);
            feed.pop();
        }
        reverse(feeed.begin(), feeed.end());
        return feeed;
    }
    
    void follow(int followerId, int followeeId) {
        ++timestamp;
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        ++timestamp;
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
