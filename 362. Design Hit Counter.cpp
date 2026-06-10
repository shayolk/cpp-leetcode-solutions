class HitCounter {
    int n;
    queue<pair<int,int>> hits;

public:
    HitCounter() {
        n = 0;
    }
    
    void hit(int timestamp) {
        if (!hits.empty() && hits.back().first == timestamp) {
            ++hits.back().second;
        } else {
            hits.push({timestamp, 1});
        }
        ++n;
    }
    
    int getHits(int timestamp) {
        while (!hits.empty() && hits.front().first <= timestamp - 300) {
            n -= hits.front().second;
            hits.pop();
        }
        return n;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
