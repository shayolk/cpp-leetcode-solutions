class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = n + 1, sum = 0;
        int l = 0, r = 0;
        while (r < n) {
            sum += nums[r++];
            while (sum >= target) {
                ans = min(ans, r - l);
                sum -= nums[l++];
            }
        }
        if (ans == n + 1) {
            return 0;
        }
        return ans;
    }
};
