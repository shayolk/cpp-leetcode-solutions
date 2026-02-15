class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(128, -1);
        int n = s.size(), ans = 0, cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (last[s[i]] == -1 || last[s[i]] < i - cnt) {
                ++cnt;
            } else {
                cnt = i - last[s[i]];
            }
            last[s[i]] = i;
            ans = max(ans, cnt);
        }
        return ans;
    }
};
