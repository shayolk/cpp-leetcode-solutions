class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        for (int i = 0; i + 2 < n; ++i) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum >= target) {
                    --r;
                } else {
                    ans += (r - l);
                    ++l;
                }
            }
        }
        return ans;
    }
};
