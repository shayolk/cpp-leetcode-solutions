class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        vector<unsigned long long> dp(amount + 1);
        dp[0] = 1;
        for (int coin: coins) {
            for (int i = 0; i < amount; ++i) {
                if (!dp[i]) {
                    continue;
                }
                if (i + coin <= amount) {
                    dp[i + coin] += dp[i];
                }
            }
        }
        return dp[amount];
    }
};
