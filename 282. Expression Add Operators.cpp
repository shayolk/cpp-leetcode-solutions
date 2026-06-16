class Solution {
    string num;
    int n, target;
    vector<string> ans;

    void dfs(int i, long long curr, string now, long long last) {
        if (i == n && curr == target) {
            ans.push_back(now);
            return;
        }
        for (int j = i; j < n; ++j) {
            if (j > i && num[i] == '0') {
                break;
            }
            string st = num.substr(i, j - i + 1);
            long long here = stoll(st);
            dfs(j + 1, curr + here, now + '+' + st, here);
            dfs(j + 1, curr - here, now + '-' + st, -here);
            dfs(j + 1, curr - last + last * here, now + '*' + st, last * here);
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        n = num.size();
        this->num = num;
        this->target = target;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && num[0] == '0') {
                break;
            }
            string st = num.substr(0, i + 1);
            long long here = stoll(st);
            dfs(i + 1, here, st, here);
        }
        return ans;
    }
};
