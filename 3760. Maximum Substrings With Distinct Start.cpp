class Solution {
public:
    int maxDistinct(string s) {
        int mask = 0, ans = 0;
        for (char c: s) {
            int bit = 1 << (c - 'a');
            if (!(mask & bit)) {
                mask |= bit;
                ++ans;
                if (ans == 26) {
                    break;
                }
            }
        }
        return ans;
    }
};
