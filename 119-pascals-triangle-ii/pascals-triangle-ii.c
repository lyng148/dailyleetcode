/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int c[1000][1000];
int kCn(int k, int n)
{
    if (k == 0 || k == n) c[k][n] = 1;
    else if (c[k][n] == 0) 
        c[k][n] = kCn(k - 1, n - 1) + kCn(k, n - 1);
    return c[k][n];
}

int* getRow(int rowIndex, int* returnSize){
    memset(c, 0, sizeof(c));
    int *ans = (int *)malloc((rowIndex + 1) * sizeof(int));
    for (int j = 0; j <= rowIndex; j++)
    {
        ans[j] = kCn(j, rowIndex);
    }
    *returnSize = rowIndex + 1;
    return ans;
}