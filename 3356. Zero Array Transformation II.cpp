class Solution {
    bool find(vector<int>& nums, vector<vector<int>>& queries, int target) {
        int n = nums.size();
        vector<int> sum(n + 1);
        for (int i = 0; i < target; ++i) {
            auto q = queries[i];
            sum[q[0]] += q[2];
            sum[q[1] + 1] -= q[2];
        }
        for (int i = 1; i < n; ++i) {
            sum[i] += sum[i - 1];
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > sum[i]) {
                return false;
            }
        }
        return true;
    }

public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        int ans = n + 1, l = 0, r = n, mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (find(nums, queries, mid)) {
                ans = min(ans, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (ans == n + 1) {
            return -1;
        }
        return ans;
    }
};
