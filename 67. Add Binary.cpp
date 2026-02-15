class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int n = a.size(), m = b.size();
        string sum;
        int i = 0, j = 0;
        bool c = false;
        while (i < n && j < m) {
            int s = (a[i++] - '0') + (b[j++] - '0') + c;
            c = s > 1;
            if (s == 0 || s == 2) {
                sum.push_back('0');
            } else {
                sum.push_back('1');
            }
        }
        while (i < n) {
            int s = (a[i++] - '0') + c;
            c = s > 1;
            if (s == 0 || s == 2) {
                sum.push_back('0');
            } else {
                sum.push_back('1');
            }
        }
        while (j < m) {
            int s = (b[j++] - '0') + c;
            c = s > 1;
            if (s == 0 || s == 2) {
                sum.push_back('0');
            } else {
                sum.push_back('1');
            }
        }
        if (c) {
            sum.push_back('1');
        }
        reverse(sum.begin(), sum.end());
        return sum;
    }
};
