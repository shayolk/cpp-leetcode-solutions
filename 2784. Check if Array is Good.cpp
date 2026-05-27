class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n);
        for (int num: nums) {
            if (num >= n) {
                return false;
            }
            if (num < n - 1 && count[num]) {
                return false;
            }
            ++count[num];
        }
        return count[n - 1] == 2;
    }
};
