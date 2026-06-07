class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto before = [&](vector<int>& in) {
            return in[1] < newInterval[0];
        };
        auto overlap = [&](vector<int>& in) {
            return max(in[0], newInterval[0]) <= min(in[1], newInterval[1]);
        };
        auto after = [&](vector<int>& in) {
            return in[0] > newInterval[1];
        };
        bool done = false;
        vector<vector<int>> ans;
        for (auto in: intervals) {
            if (before(in)) {
                ans.push_back(in);
                continue;
            }
            if (after(in)) {
                if (!done) {
                    ans.push_back(newInterval);
                    done = true;
                }
                ans.push_back(in);
                continue;
            }
            if (overlap(in)) {
                newInterval = {min(in[0], newInterval[0]), max(in[1], newInterval[1])};
            } else {
                ans.push_back(newInterval);
                done = true;
            }
        }
        if (!done) {
            ans.push_back(newInterval);
            done = true;
        }
        return ans;
    }
};
