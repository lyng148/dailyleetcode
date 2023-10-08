int maxDotProduct(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int n = nums1Size;
    int m = nums2Size;
    int memo[n][m];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            memo[i][j] = INT_MIN;
        }
    }
    
    return dp(nums1, n, nums2, m, 0, 0, memo);
}

int dp(int* nums1, int n, int* nums2, int m, int i, int j, int memo[n][m]) {
    if (i == n || j == m) {
        return INT_MIN;
    }
    
    if (memo[i][j] != INT_MIN) {
        return memo[i][j];
    }
    
    memo[i][j] = fmax(
        nums1[i] * nums2[j] + fmax(dp(nums1, n, nums2, m, i + 1, j + 1, memo), 0),
        fmax(dp(nums1, n, nums2, m, i + 1, j, memo), dp(nums1, n, nums2, m, i, j + 1, memo))
    );
    
    return memo[i][j];
}