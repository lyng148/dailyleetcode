/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** buildArray(int* target, int targetSize, int n, int* returnSize) {
    char **ans = (char**)malloc(1000 * sizeof(char*));
    for (int i = 0; i < 1000; i++)
    {
        ans[i] = (char*)malloc(5 * sizeof(char));
    }
    int idx_1 = 0;   // idx_1 store current index for answer array
    int idx_2 = 0;   // store current target to check
    int i = 1;
    while(i <= target[targetSize - 1])
    {
        strcpy(ans[idx_1++],"Push");
        if (target[idx_2] != i)
        {
            strcpy(ans[idx_1++], "Pop");
        }
        else idx_2++;
        i++;
    }
    *returnSize = idx_1;
    return ans;
}