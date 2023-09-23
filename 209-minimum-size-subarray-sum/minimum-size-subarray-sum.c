int min(int a, int b){return a < b ? a : b;}
int minSubArrayLen(int target, int* nums, int numsSize){
    int l = 0, r = numsSize - 1, ans = 100001;
    int sum = 0;
    for (r = 0; r < numsSize; r++)
    {
        sum += nums[r];
        while (sum >= target)
        {
            sum -= nums[l++];
        }
        if (l > 0 && sum < target)
        {
            sum += nums[l-1];
            l -= 1;
        }
        if (sum >= target) ans = min(ans, r - l + 1);
    }
    if (ans != 100001)return ans;
    return 0;
}