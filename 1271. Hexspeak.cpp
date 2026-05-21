class Solution {
    static constexpr string error = "ERROR";

public:
    string toHexspeak(string num) {
        string ans = "";
        long long n = stoll(num);
        while (n) {
            int rem = n % 16;
            if (rem == 0) {
                ans = 'O' + ans;
            } else if (rem == 1) {
                ans = 'I' + ans;
            } else if (rem <= 9) {
                return error;
            } else {
                ans = char('A' + rem - 10) + ans;
            }
            n /= 16;
        }
        return ans;
    }
};
