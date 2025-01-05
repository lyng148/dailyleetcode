class Solution {
public:
    bool isInterleave(string A, string B, string C) {
    int m = A.length(), n = B.length();
    
    // Nếu tổng độ dài của A và B khác C, không thể là xâu ghép
    if (m + n != C.length()) return false;

    // Tạo bảng DP
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    // Duyệt qua từng ký tự của A, B, và C
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            // Nếu cả hai chuỗi A và B đều rỗng, thì C cũng phải rỗng
            if (i == 0 && j == 0) {
                dp[i][j] = true;
            }
            // Nếu chỉ A đóng góp
            else if (i > 0 && C[i + j - 1] == A[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            }
            // Nếu chỉ B đóng góp
            else if (j > 0 && C[i + j - 1] == B[j - 1]) {
                dp[i][j] = dp[i][j - 1];
            }
            // Nếu cả A và B đều đóng góp
            if (i > 0 && j > 0 && C[i + j - 1] == A[i - 1] && C[i + j - 1] == B[j - 1]) {
                dp[i][j] = dp[i][j] || dp[i - 1][j] || dp[i][j - 1];
            }
        }
    }

    return dp[m][n];
}
};