class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        int n = arr.size();
        vector<int> last = arr;
        bool change = true;
        while (change) {
            change = false;
            for (int i = 1; i < n - 1; ++i) {
                if (last[i] < last[i - 1] && last[i] < last[i + 1]) {
                    ++arr[i];
                    change = true;
                }
                if (last[i] > last[i - 1] && last[i] > last[i + 1]) {
                    --arr[i];
                    change = true;
                }
            }
            last = arr;
        }
        return arr;
    }
};
