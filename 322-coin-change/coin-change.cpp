class Solution {
public:
    int MinCoin(vector<int> &coins, int amount) {
    int dp[++amount];
    dp[0] = 0;
    sort(coins.begin(), coins.end());
    for (int i = 1; i < amount; i++){
        dp[i] = INT_MAX;
        for (int c : coins) {
            if (i - c < 0)
                break;
            if (dp[i - c] != INT_MAX) 
                dp[i] = min(dp[i], 1 + dp[i - c]);
        }
    }
    return dp[--amount] != INT_MAX ? dp[amount] : -1;
}

int coinChange(vector<int> &coins, int amount) {
    return MinCoin(coins, amount);
}

};