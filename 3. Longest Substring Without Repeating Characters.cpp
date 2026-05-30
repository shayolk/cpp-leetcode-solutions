class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(128, -1);
        int l = 0, r = 0, n = s.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            r = i;
            if (last[s[i]] != -1) {
                l = max(l, last[s[i]] + 1);
            }
            last[s[i]] = i;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
