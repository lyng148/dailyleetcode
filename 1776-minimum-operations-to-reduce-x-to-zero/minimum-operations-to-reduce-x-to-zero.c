int max1(int a, int b){return a > b ? a : b;}
int minOperations(int* nums, int numsSize, int x){
    int target = 0;
    int max = 0; //here we will find the longest subarray with sum = target with target = total sum - x
    for (int i = 0; i < numsSize; i++)
    {
        target += nums[i];
    }
    target -= x;
    if (target == 0) return numsSize;
    if (target < 0) return -1;
    int sum = 0;
    int l = 0, r = 0;
    for (int r = 0; r < numsSize; r++)
    {
        sum += nums[r];
        while (sum > target)
        {
            sum -= nums[l++];
        }
        if (sum == target) max = max1(max, r - l + 1);
    }
    if (max == 0) return -1;
    return numsSize - max;
}
