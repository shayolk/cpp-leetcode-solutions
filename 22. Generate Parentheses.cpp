class Solution {
    vector<string> ans;

    void generate(int i, int& n, string& s, int op, int cl) {
        if (i == 2 * n) {
            if (op == cl) {
                ans.push_back(s);
            }
            return;
        }
        if (op < n && cl < n) {
            s += "(";
            generate(i + 1, n, s, op + 1, cl);
            s.pop_back();
        }
        if (cl < op) {
            s += ")";
            generate(i + 1, n, s, op, cl + 1);
            s.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        string s;
        generate(0, n, s, 0, 0);
        return ans;
    }
};
