class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) {
        sort(weight.begin(), weight.end());
        int n = weight.size(), i = 0, cap = 5000;
        while (i < n && cap && weight[i] <= cap) {
            cap -= weight[i++];
        }
        return i;
    }
};
