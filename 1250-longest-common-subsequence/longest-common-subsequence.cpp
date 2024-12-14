class Solution {
public:
    int longestCommonSubsequence(string text1, string text2)
{
    int length1 = text1.length();
    int length2 = text2.length();
    int dp[length1 + 1][length2 + 1]; // do dai xau con chung dai nhat voi length1 la do dai text1 va con lai
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= length1; i++){
        for (int j = 1; j <= length2; j++){
            if (text1[i - 1] == text2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    return dp[length1][length2];
}
};