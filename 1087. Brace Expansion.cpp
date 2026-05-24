class Solution {
    int tot;
    vector<vector<char>> letters;
    vector<string> ans;

    void dfs(int now, string s) {
        if (now == tot) {
            ans.push_back(s);
            return;
        }
        for (int i = 0; i < letters[now].size(); ++i) {
            dfs(now + 1, s + letters[now][i]);
        }
    }

public:
    vector<string> expand(string s) {
        int i = 0, n = s.size();
        while (i < n) {
            vector<char> now;
            if (s[i] != '{') {
                now.push_back(s[i]);
                letters.push_back(now);
                ++i;
                continue;
            }
            ++i;
            while (i < n && s[i] != '}') {
                if (s[i] == ',') {
                    ++i;
                } else {
                    now.push_back(s[i++]);
                }
            }
            ++i;
            sort(now.begin(), now.end());
            letters.push_back(now);
        }
        tot = letters.size();
        dfs(0, "");
        return ans;
    }
};
