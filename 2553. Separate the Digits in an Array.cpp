class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (int num: nums) {
            int len = ans.size();
            while (num) {
                ans.push_back(num % 10);
                num /= 10;
            }
            reverse(ans.begin() + len, ans.end());
        }
        return ans;
    }
};
