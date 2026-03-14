class Solution {
public:
    string getHappyString(int n, int k) {
        stack<string> ss;
        ss.push("");
        while (!ss.empty()) {
            string s = ss.top();
            ss.pop();
            if (s.size() == n) {
                --k;
                if (k == 0) {
                    return s;
                }
                continue;
            }
            for (char c = 'c'; c >= 'a'; --c) {
                if (!s.empty() && s.back() == c) {
                    continue;
                }
                ss.push(s + c);
            }
        }
        return "";
    }
};
