class Solution {
    int calc(int n) {
        return n * (n + 1) / 2;
    }

public:
    int countLetters(string s) {
        int now = 0, cnt = 0, ans = 0;
        for (char c: s) {
            if ((c - 'a') == now) {
                ++cnt;
            } else {
                if (cnt) {
                    ans += calc(cnt);
                }
                now = (c - 'a');
                cnt = 1;
            }
        }
        if (cnt) {
            ans += calc(cnt);
        }
        return ans;
    }
};
