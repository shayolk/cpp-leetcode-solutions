class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        for (int num: nums) {
            nums[abs(num) - 1] *= -1;
        }
        int rep = -1, miss = -1;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                if (rep == -1) {
                    rep = i + 1;
                } else {
                    miss = i + 1;
                    break;
                }
            }
        }
        int cnt = 0;
        for (int num: nums) {
            if (abs(num) == rep) {
                ++cnt;
            }
        }
        if (cnt == 2) {
            return {rep, miss};
        }
        return {miss, rep};
    }
};
