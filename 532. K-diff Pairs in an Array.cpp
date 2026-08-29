class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = lower_bound(nums.begin() + i + 1, nums.end(), nums[i] + k) - nums.begin();
            if (j < n && nums[j] == nums[i] + k) {
                ++ans;
            }
        }
        return ans;
    }
};
