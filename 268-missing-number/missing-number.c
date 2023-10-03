int missingNumber(int* nums, int n){
    int sum = 0;
    if (n % 2 == 0)
    {
        sum = (n + 1) * (n / 2);
    }
    else sum = (n + 1) / 2 * n;
    for (int i = 0; i < n; i++)
    {
        sum -= nums[i];
    }
    return sum;
}