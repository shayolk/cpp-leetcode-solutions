class Solution {
    static constexpr int M = 1e9 + 7;

public:
    int countHomogenous(string s) {
        char now = '*';
        int cnt = 0;
        long long ans = 0;
        for (char c: s) {
            if (c == now) {
                ++cnt;
                ans = (ans + cnt) % M;
            } else {
                now = c;
                cnt = 1;
                ans = (ans + cnt) % M;
            }
        }
        return ans;
    }
};
