class Solution {
public:
    string removeDuplicates(string s, int k) {
        string ans;
        vector<int> cnts;
        for (char c: s) {
            int cnt = 1;
            if (!ans.empty() && ans.back() == c) {
                cnt = cnts.back() + 1;
            }
            ans += c;
            cnts.push_back(cnt);
            if (!cnts.empty() && cnts.back() == k) {
                char here = ans.back();
                while (!ans.empty() && ans.back() == here) {
                    ans.pop_back();
                    cnts.pop_back();
                }
            }
        }
        return ans;
    }
};
