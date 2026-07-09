class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> cnt(128);
        for (char c: text) {
            ++cnt[c];
        }
        int ans = INT_MAX;
        ans = min(ans, cnt['b']);
        ans = min(ans, cnt['a']);
        ans = min(ans, cnt['l'] / 2);
        ans = min(ans, cnt['o'] / 2);
        ans = min(ans, cnt['n']);
        return ans;
    }
};
