class Solution {
public:
    int countVowelSubstrings(string word) {
        set<char> vowels({'a', 'e', 'i', 'o', 'u'});
        int lastc = -1, ans = 0, n = word.size();
        map<char,int> lastv;
        for (char v: vowels) {
            lastv[v] = -1;
        }
        for (int i = 0; i < n; ++i) {
            char c = word[i];
            if (vowels.count(c)) {
                lastv[c] = i;
            } else {
                lastc = i;
            }
            int lastvv = INT_MAX;
            for (char v: vowels) {
                lastvv = min(lastvv, lastv[v]);
            }
            ans += max(0, lastvv - lastc);
        }
        return ans;
    }
};
