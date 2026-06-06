class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        stack<int> st;
        map<int,int> nge;
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nge[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        vector<int> ans;
        for (int num: nums1) {
            if (nge.count(num)) {
                ans.push_back(nge[num]);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
