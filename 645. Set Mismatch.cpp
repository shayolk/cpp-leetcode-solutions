class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), rep = -1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1]) {
                rep = nums[i];
                break;
            }
        }
        int miss = rep;
        for (int i = 0; i < n; ++i) {
            miss ^= (i + 1);
            miss ^= nums[i];
        }
        return {rep, miss};
    }
};
