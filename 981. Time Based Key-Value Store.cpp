class TimeMap {
    map<string,vector<pair<int,string>>> store;

public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!store.count(key) || store[key].empty() || store[key][0].first > timestamp) {
            return "";
        }
        int n = store[key].size();
        int lo = 0, hi = n - 1, mid, ans = 0;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (store[key][mid].first <= timestamp) {
                ans = max(ans, mid);
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return store[key][ans].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
