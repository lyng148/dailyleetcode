int maxProfit(int* nums, int numsSize){
    int profit = 0;
    int l = 0, r;
    for (r = 1; r < numsSize; r++)
    {
        while (l < r)
        {
            if (nums[r] - nums[l] > 0)
            {
                profit += nums[r] - nums[l];
                l = r;
                break;
            }
            else l++;
        }
    }
    return profit;
}