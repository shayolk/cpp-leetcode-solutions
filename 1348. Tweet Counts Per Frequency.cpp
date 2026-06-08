class TweetCounts {
    static constexpr int min = 60;
    static constexpr int hour = 60 * min;
    static constexpr int day = 24 * hour;

    map<string,multiset<int>> tweets;

public:
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        tweets[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int interval = min;
        if (freq == "hour") {
            interval = hour;
        } else if (freq == "day") {
            interval = day;
        }
        int chunks  = (endTime - startTime) / interval + 1;
        vector<int> ans(chunks);
        if (!tweets.count(tweetName)) {
            return ans;
        }
        auto lo = tweets[tweetName].lower_bound(startTime);
        auto hi = tweets[tweetName].upper_bound(endTime);
        while (lo != hi) {
            int chunk = (*lo - startTime) / interval;
            ++ans[chunk];
            ++lo;
        }
        return ans;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
