class Solution {
public:
    string convert(string s, int numRows) {
        string ans;
        int n = s.size();
        if (numRows == 1 || n <= numRows) {
            return s;
        }
        for (int i = 0; i < n; i += (2 * numRows - 2)) {
            ans += s[i];
        }
        for (int j = 1; j < numRows - 1; ++j) {
            int up = 2 * j;
            int dn = 2 * (numRows - j - 1);
            bool down = false;
            for (int i = j; i < n; i += (down ? dn : up)) {
                ans += s[i];
                down = !down;
            }
        }
        for (int i = (numRows - 1); i < n; i += (2 * numRows - 2)) {
            ans += s[i];
        }
        return ans;
    }
};
