class Solution {
public:
    int binaryGap(int n) {
        int ans = 0, last = -1;
        for (int i = 0; i < 31; ++i) {
            if (n & (1<<i)) {
                if (last != -1) {
                    ans = max(ans, i - last);
                }
                last = i;
            }
        }
        return ans;
    }
};
