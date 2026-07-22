class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int one = -1, two = -1, ans = INT_MAX;
        int n = wordsDict.size();
        for (int i = 0; i < n; ++i) {
            if (wordsDict[i] == word1) {
                one = i;
            } else if (wordsDict[i] == word2) {
                two = i;
            }
            if (one != -1 && two != -1) {
                ans = min(ans, abs(one - two));
            }
        }
        if (ans == INT_MAX) {
            ans = -1;
        }
        return ans;
    }
};
