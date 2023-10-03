int numIdenticalPairs(int* nums, int numsSize){
    int count = 0;
    int a[101] = {0};
    for (int i = 0; i < numsSize; i++)
    {
        a[nums[i]]++;
    }
    for (int i = 1; i < 101; i++)
    {
        int k = a[i];
        if (k > 1)
        {
            if (k % 2 == 0)
            {
                count += k / 2 * (k - 1);
                continue;
            }
            else
            {
                count += (k - 1) / 2 * k;
                continue;
            }
        }
    }
    return count;
}