class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> cnt;
        for (char c: s) {
            ++cnt[c];
        }
        bool one = false;
        int ans = 0;
        for (auto& [c, i]: cnt) {
            if (i % 2) {
                one = true;
            }
            ans += (i / 2) * 2;
        }
        return ans + one;
    }
};
