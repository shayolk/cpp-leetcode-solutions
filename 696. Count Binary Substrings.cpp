class Solution {
public:
    int countBinarySubstrings(string s) {
        int curr = 0, prev = 0, ans = 0;
        char last = '*';
        for (char c: s) {
            if (c != last) {
                prev = curr;
                curr = 0;
            }
            ++curr;
            last = c;
            if (curr <= prev) {
                ++ans;
            }
        }
        return ans;
    }
};
