class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, -1);
        set<int> dry;
        map<int,int> last;
        for (int i = 0; i < n; ++i) {
            if (rains[i]) {
                if (last.count(rains[i])) {
                    auto ind = dry.upper_bound(last[rains[i]]);
                    if (ind == dry.end()) {
                        return {};
                    }
                    ans[*ind] = rains[i];
                    dry.erase(ind);
                }
                last[rains[i]] = i;
            } else {
                dry.insert(i);
            }
        }
        for (auto& d: dry) {
            ans[d] = 1;
        }
        return ans;
    }
};
