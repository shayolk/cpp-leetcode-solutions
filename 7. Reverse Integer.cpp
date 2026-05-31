class Solution {
public:
    int reverse(int x) {
        bool neg = false;
        if (x < 0) {
            if (x == INT_MIN) {
                return 0;
            }
            neg = true;
            x = -x;
        }
        int ans = 0;
        while (x) {
            if (ans > INT_MAX / 10) {
                return 0;
            }
            int one = ans * 10;
            int two = x % 10;
            if ((one & 1<<31) && (two & (1<<31))) {
                return 0;
            }
            ans = one + two;
            x /= 10;
        }
        if (neg) {
            return -ans;
        }
        return ans;
    }
};
