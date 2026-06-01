class Solution {
    bool lower(char c) {
        return c >= 'a' && c <= 'z';
    }

    bool upper(char c) {
        return c >= 'A' && c <= 'Z';
    }

    bool numer(char c) {
        return c >= '0' && c <= '9';
    }

    bool valid(char c) {
        return lower(c) || upper(c) || numer(c);
    }

    char conv(char c) {
        if (lower(c) || numer(c)) {
            return c;
        }
        return 'a' + (c - 'A');
    }

public:
    bool isPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            while (l <= r && !valid(s[l])) {
                ++l;
            }
            while (l <= r && !valid(s[r])) {
                --r;
            }
            if (l > r) {
                return true;
            }
            s[l] = conv(s[l]);
            s[r] = conv(s[r]);
            if (s[l] != s[r]) {
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }
};
