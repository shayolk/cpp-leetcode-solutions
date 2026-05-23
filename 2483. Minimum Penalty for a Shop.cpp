class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> pre(n + 1), suf(n + 1);
        for (int i = 0; i < n; ++i) {
            pre[i] = (customers[i] == 'N');
            if (i) {
                pre[i] += pre[i - 1];
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            suf[i] = (customers[i] == 'Y');
            suf[i] += suf[i + 1];
        }
        int ind = -1, mn = INT_MAX;
        for (int i = 0; i <= n; ++i) {
            int sum = suf[i];
            if (i) {
                sum += pre[i - 1];
            }
            if (sum < mn) {
                mn = sum;
                ind = i;
            }
        }
        return ind;
    }
};
