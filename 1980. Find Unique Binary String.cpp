class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        int maxn = 1, nn = n;
        while (nn--) {
            maxn *= 2;
        }
        set<int> si;
        for (string num: nums) {
            int now = 0;
            for (int i = 0; i < n; ++i) {
                now += (num[n - 1 - i] - '0') * (1 << i);
            }
            si.insert(now);
        }
        int ans = 0;
        for (int i = 0; i <= maxn; ++i) {
            if (!si.count(i)) {
                ans = i;
                break;
            }
        }
        string ret;
        for (int i = 0; i < n; ++i) {
            if (ans & (1 << i)) {
                ret += '1';
            } else {
                ret += '0';
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
