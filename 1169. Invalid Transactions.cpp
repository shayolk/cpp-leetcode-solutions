class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<vector<string>> trans;
        for (string t: transactions) {
            vector<string> here;
            string now = "";
            for (char c: t) {
                if (c != ',') {
                    now += c;
                } else {
                    here.push_back(now);
                    now = "";
                }
            }
            here.push_back(now);
            trans.push_back(here);
        }
        int n = trans.size();
        vector<bool> valid(n, true);
        for (int i = 0; i < n; ++i) {
            if (stoi(trans[i][2]) > 1000) {
                valid[i] = false;
            }
            for (int j = i + 1; j < n; ++j) {
                if (trans[i][0] == trans[j][0] && trans[i][3] != trans[j][3]) {
                    if (abs(stoi(trans[i][1]) - stoi(trans[j][1])) <= 60) {
                        valid[i] = false;
                        valid[j] = false;
                    }
                }
            }
        }
        vector<string> ans;
        for (int i = 0; i < n; ++i) {
            if (!valid[i]) {
                ans.push_back(transactions[i]);
            }
        }
        return ans;
    }
};
