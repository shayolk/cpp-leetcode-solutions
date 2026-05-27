class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int m = strs.size();
        int n = strs[0].size();
        for (int i = 0; i < n; ++i) {
            bool match = true;
            for (int j = 0; j < m; ++j) {
                if (strs[j].size() < i || strs[j][i] != strs[0][i]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                ans += strs[m - 1][i];
            } else {
                break;
            }
        }
        return ans;
    }
};
