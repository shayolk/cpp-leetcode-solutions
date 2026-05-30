class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        long long n = 1;
        int cnt = 0;
        while (x / n) {
            n *= 10;
            ++cnt;
        }
        long long l = 1;
        for (int i = 1; i <= cnt / 2; ++i) {
            l *= 10;
        }
        long long r = l;
        if (cnt % 2 == 0) {
            r /= 10;
        }
        cnt = (cnt + 1) / 2;
        while (cnt--) {
            if ((x / l) % 10 != (x / r) % 10) {
                return false;
            }
            l *= 10;
            r /= 10;
        }
        return true;
    }
};
