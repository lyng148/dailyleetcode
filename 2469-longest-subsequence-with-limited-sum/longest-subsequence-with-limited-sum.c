int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int* answerQueries(int* nums, int numsSize, int* queries, int queriesSize, int* returnSize){
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    int *ans = (int *)malloc(queriesSize * sizeof(int));
    // V de tim ra chuoi dai nhat => luon dung tat ca cac so tu be den lon
    // => lam prefix sum de tinh luon tong
    // dung binary search tim ra gia tri <= voi gia tri can tim;
    if (numsSize > 1)
    {
        for (int i = 1; i < numsSize; i++)
        {
            nums[i] += nums[i - 1];
        }
    }

    for (int i = 0; i < queriesSize; i++)
    {
        int l = 0, r = numsSize - 1, k = 0;
        while(l <= r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] <= queries[i])
            {
                k = m + 1;
                l = m + 1;
            }
            else r = m - 1;
        }
        ans[i] = k;
    }
    *returnSize = queriesSize;
    return ans;
}