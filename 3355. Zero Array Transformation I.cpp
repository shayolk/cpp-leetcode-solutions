class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> sum(n + 1);
        for (auto q: queries) {
            ++sum[q[0]];
            --sum[q[1] + 1];
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
};
