class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int diff = INT_MAX, ans = 0;
        for (int i = 0; i + 2 < n; ++i) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                int now = abs(sum - target);
                if (now < diff) {
                    diff = now;
                    ans = sum;
                }
                if (sum > target) {
                    --r;
                } else if (sum < target) {
                    ++l;
                } else {
                    return ans;
                }
            }
        }
        return ans;
    }
};
