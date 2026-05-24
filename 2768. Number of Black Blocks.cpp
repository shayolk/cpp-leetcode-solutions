class Solution {
    int m, n;
    static constexpr int dr[4] = {0, 0, -1, -1};
    static constexpr int dc[4] = {0, -1, 0, -1};

    bool safe(int r, int c) {
        return r >= 0 && r < m && c >= 0 && c < n && r + 1 >= 0 && r + 1 < m && c + 1 >= 0 && c + 1 < n;;
    }

public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        this->m = m;
        this->n = n;
        map<pair<int,int>,int> mp;
        for (auto co: coordinates) {
            for (int d = 0; d < 4; ++d) {
                int r = co[0] + dr[d];
                int c = co[1] + dc[d];
                if (safe(r, c)) {
                    ++mp[{r, c}];
                }
            }
        }
        vector<long long> ans(5);
        for (int i = 0; i < 5; ++i) {
            if (i == 0) {
                long long here = 1ll * (n - 1) * (m - 1) - mp.size();
                ans[i] = here;
            } else {
                long long here = 0;
                for (auto p: mp) {
                    if (p.second == i) {
                        ++here;
                    }
                }
                ans[i] = here;
            }
        }
        return ans;
    }
};
