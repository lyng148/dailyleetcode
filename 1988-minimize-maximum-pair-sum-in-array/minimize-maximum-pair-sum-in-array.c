int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int minPairSum(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    int max = nums[0] + nums[numsSize - 1];
    for (int i = 1; i < numsSize / 2; i++)
    {
        int a = nums[i] + nums[numsSize - 1 - i];
        if (a > max) max = a;
    }
    return max;
}