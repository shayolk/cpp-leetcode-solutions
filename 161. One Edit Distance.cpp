class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int sn = s.size(), tn = t.size();
        if (sn < tn) {
            return isOneEditDistance(t, s);
        }
        if (abs(sn - tn) > 1 || (!sn && !tn)) {
            return false;
        }
        if (!tn) {
            return (sn == 1);
        }
        if (sn == tn) {
            int sum = 0;
            for (int i = 0; i < sn; ++i) {
                if (s[i] != t[i]) {
                    ++sum;
                }
                if (sum > 1) {
                    return false;
                }
            }
            return (sum == 1);
        }
        int i = 0, j = 0, sum = 0;
        while (i < sn && j < tn) {
            if (s[i] != t[j]) {
                ++sum;
                ++i;
                continue;
            }
            if (sum > 1) {
                return false;
            }
            ++i;
            ++j;
        }
        sum += (sn - i) + (tn - j);
        return (sum == 1);
    }
};
