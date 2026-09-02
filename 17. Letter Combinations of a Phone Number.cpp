class Solution {
    vector<vector<char>> letters = {
        {},
        {},
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'},
    };

    int n;
    vector<string> ans;

    void find(int ind, string& digits, string& now) {
        if (ind == n) {
            ans.push_back(now);
            return;
        }
        int digit = (digits[ind] - '0');
        for (char c: letters[digit]) {
            now += c;
            find(ind + 1, digits, now);
            now.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        n = digits.size();
        string s;
        find(0, digits, s);
        return ans;
    }
};
