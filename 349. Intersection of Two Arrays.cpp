class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        int n1 = nums1.size(), n2 = nums2.size();
        int i1 = 0, i2 = 0;
        while (i1 < n1 && i2 < n2) {
            while (i1 + 1 < n1 && nums1[i1] == nums1[i1 + 1]) {
                ++i1;
            }
            while (i2 + 1 < n2 && nums2[i2] == nums2[i2 + 1]) {
                ++i2;
            }
            if (nums1[i1] == nums2[i2]) {
                ans.push_back(nums1[i1]);
                ++i1;
                ++i2;
            } else if (nums1[i1] < nums2[i2]) {
                ++i1;
            } else {
                ++i2;
            }
        }
        return ans;
    }
};
