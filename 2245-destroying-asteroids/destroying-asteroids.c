int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

bool asteroidsDestroyed(int mass, int* nums, int numsSize){
    long long sum = mass;
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    for (int i = 0; i < numsSize; i++)
    {
        if (sum >= nums[i])
        {
            sum += nums[i];
        }
        else return false;
    }
    return true;
}