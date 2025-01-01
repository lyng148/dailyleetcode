class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int height = triangle.size();
        vector<vector<int>> dp;
        for (int i = 0; i < height; i++) {
            vector<int> newVt;
            for (int j = 0; j <= i; j++) {
                newVt.push_back(INT_MAX);
            }
            dp.push_back(newVt);
        }
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < height; i++) {
            for (int j = 0; j <= i; j++) {
                if (j < i)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + triangle[i][j]);
                if (j > 0) 
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + triangle[i][j]);
            }
        }
        int minRes = INT_MAX;
        for (int i = 0; i < height; i++) {
            minRes = min(dp[height - 1][i], minRes);
        }
        return minRes;
    }
};