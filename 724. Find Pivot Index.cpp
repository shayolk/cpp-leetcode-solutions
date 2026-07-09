class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> suf(n + 1);
        for (int i = n - 1; i >= 0; --i) {
            suf[i] = nums[i] + suf[i + 1];
        }
        int pre = 0;
        for (int i = 0; i < n; ++i) {
            if (i) {
                pre += nums[i - 1];
            }
            if (pre == suf[i + 1]) {
                return i;
            }
        }
        return -1;
    }
};
