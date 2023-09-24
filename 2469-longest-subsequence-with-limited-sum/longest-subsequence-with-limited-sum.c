int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int* answerQueries(int* nums, int numsSize, int* queries, int queriesSize, int* returnSize){
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    int *ans = (int *)malloc(queriesSize * sizeof(int));

    if (numsSize > 1)
    {
        for (int i = 1; i < numsSize; i++)
        {
            nums[i] += nums[i - 1];
        }
    }

    for (int i = 0; i < queriesSize; i++)
    {
        int index = 0;
        while (nums[index] <= queries[i] && index < numsSize - 1)
        {
            index++;
        }
        if (nums[numsSize - 1] <= queries[i]) index++;
        ans[i] = index;
    }
    *returnSize = queriesSize;
    return ans;
}