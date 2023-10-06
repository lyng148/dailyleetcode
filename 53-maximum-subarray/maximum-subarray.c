int maxSubArray(int* nums, int numsSize){
    int sum1 = 0, sum2 = 0;
    int tmp = -2147483648;

    for (int i = 0; i < numsSize; i++)
    {
        sum1 += nums[i];
        if (sum1 <= 0)
        {
            if (sum1 > tmp) tmp = sum1;
            sum1 = 0;
        }
        sum2 = sum2 > sum1 ? sum2 : sum1;
    }
    if (sum2 > 0) return sum2;
    return tmp; 
     
}