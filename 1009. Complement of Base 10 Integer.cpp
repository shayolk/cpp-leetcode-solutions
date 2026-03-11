class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) {
            return 1;
        }
        string nn;
        int last = 31;
        for (int i = 0; i < 31; ++i) {
            if (n & (1<<i)) {
                nn += '1';
                last = i + 1;
            } else {
                nn += '0';
            }
        }
        int res = 0;
        for (int i = 0; i < last; ++i) {
            if (nn[i] == '0') {
                res += (1<<i);
            }
        }
        return res;
    }
};
