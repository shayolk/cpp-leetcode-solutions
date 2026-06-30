class Solution {
public:
    int shortestWay(string source, string target) {
        set<char> sc;
        for (char c: source) {
            sc.insert(c);
        }
        for (char c: target) {
            if (!sc.count(c)) {
                return -1;
            }
        }
        int sn = source.size();
        int tn = target.size();
        vector<vector<int>> nxt(sn + 1, vector<int> (26, sn));
        for (int j = 0; j < 26; ++j) {
            for (int i = sn - 1; i >= 0; --i) {
                nxt[i][j] = nxt[i + 1][j];
                if (source[i] == ('a' + j)) {
                    nxt[i][j] = i;
                }
            }
        }
        int s = 0, t = 0, ans = 1;
        while (t < tn) {
            if (s == sn) {
                ++ans;
                s = 0;
            }
            s = nxt[s][target[t] - 'a'];
            if (s == sn) {
                ++ans;
                s = 0;
            } else {
                ++s;
                ++t;
            }
        }
        return ans;
    }
};
