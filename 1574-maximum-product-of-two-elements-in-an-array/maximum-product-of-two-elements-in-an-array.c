int maxProduct(int* nums, int numsSize) {
    if (numsSize < 2) return 0;
    int max1 = nums[0] >= nums[1] ? nums[0] : nums[1];
    int max2 = nums[0] < nums[1] ? nums[0] : nums[1]; // max1 bigger than max2
    if (numsSize > 2)
    for (int i = 2; i < numsSize; i++)
    {
        if (nums[i] > max1)
        {
            max2 = max1;
            max1 = nums[i];
        } 
        else if (nums[i] > max2)
        {
            max2 = nums[i];
        }
    }
    return (max2 - 1) * (max1 - 1);
}