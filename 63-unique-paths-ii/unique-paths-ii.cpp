class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();

        if (n == 1 && m == 1){
            return !nums[n - 1][m - 1];
        }
          
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (nums[i][j] != 1) {
                    if (i > 0) {
                        if (nums[i - 1][j] != 1)
                            dp[i][j] += dp[i - 1][j];
                    }
                    if (j > 0) {
                        if (nums[i][j - 1] != 1)
                            dp[i][j] += dp[i][j - 1];
                    }
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};