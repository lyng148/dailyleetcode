int max1(int a, int b){return a > b ? a : b;}

int maxProfit(int* nums, int pricesSize){
    int max = 0, min = 2147483647;
    int r = 0, l = 0, sum = 0;
    for (int r = 0; r < pricesSize; r++)
    {
        while (l < r)
        {
            if (nums[l] < min) min = nums[l];
            l++;
        }
        max = max1(max, nums[r] - min);
    }
    return max;
}