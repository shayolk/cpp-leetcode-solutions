class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0, r = -1, ans = 0, mx = 0;
        vector<int> cnt(26);
        while (r + 1 < n) {
            int c = s[++r] - 'A';
            ++cnt[c];
            if (cnt[c] > mx) {
                mx = cnt[c];
            }
            if (r - l + 1 - mx <= k) {
                ++ans;
            } else {
                --cnt[s[l++] - 'A'];
            }
        }
        return ans;
    }
};
