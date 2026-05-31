class Solution {
    int calc(int n) {
        int res = 0;
        while (n) {
            int rem = n % 10;
            res += (rem * rem);
            n /= 10;
        }
        return res;
    }

public:
    bool isHappy(int n) {
        int slow = n;
        int fast = calc(n);
        while (fast != 1 && slow != fast) {
            slow = calc(slow);
            fast = calc(calc(fast));
        }
        return fast == 1;
    }
};
