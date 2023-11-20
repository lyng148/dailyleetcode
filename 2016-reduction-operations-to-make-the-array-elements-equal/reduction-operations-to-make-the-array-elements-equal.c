int cmpfunc (const void * a, const void * b)
{
   return ( -*(int*)a + *(int*)b );
}


int reductionOperations(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    int l = 0, r = 0, ans = 0;
    for (r = 1; r < numsSize; r++)
    {
        if (nums[l] > nums[r])
        {
            ans+= r;
            l = r;
        }
    }
    return ans;
}