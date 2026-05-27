class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), mx = 1, ml = 0, mr = 0;
        for (int i = 1; i < n; ++i) {
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                --l;
                ++r;
            }
            if (r - l - 1 > mx) {
                mx = r - l - 1;
                ml = l + 1;
                mr = r - 1;
            }
            l = i - 1, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                --l;
                ++r;
            }
            if (r - l - 1 > mx) {
                mx = r - l - 1;
                ml = l + 1;
                mr = r - 1;
            }
        }
        return s.substr(ml, mr - ml + 1);
    }
};
