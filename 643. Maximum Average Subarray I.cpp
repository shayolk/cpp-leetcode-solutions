class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        long long ans = sum;
        for (int i = k; i < n; ++i) {
            sum = sum - nums[i - k] + nums[i];
            if (sum > ans) {
                ans = sum;
            }
        }
        return 1.0 * ans / k;
    }
};
