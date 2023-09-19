int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int countPairs(int* nums, int Size, int target){
    int i = 0, j = Size - 1, count = 0;
    qsort(nums, Size, sizeof(int), cmpfunc);
    while (i < j)
    {
        if (nums[i] + nums[j] < target)
        {
            count += j - i;
            i++;
        }
        else j--;
    }

    return count;
}