class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n - 1][n - 1];
        int ans = r, mid;

        auto count = [&](int num) {
            int cnt = 0, c = n - 1;
            for (int r = 0; r < n; ++r) {
                while (c >= 0 && matrix[r][c] > num) {
                    --c;
                }
                cnt += (c + 1);
            }
            return cnt;
        };

        while (l <= r) {
            mid = l + (r - l) / 2;
            if (count(mid) >= k) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
