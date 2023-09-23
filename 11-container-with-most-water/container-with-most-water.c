int max(int a, int b){return a > b ? a : b;}

int maxArea(int* nums, int numsSize){
    int l = 0, r = numsSize - 1;
    int v; 
    int max1 = 0;
    while (l <= r)
    {
        if (nums[l] < nums[r])
        {
            v = nums[l] * (r - l);
            max1 = max(max1, v); 
            l++;
        }    
        else
        {
            v = nums[r] * (r - l);
            max1 = max(max1, v); 
            r--;
        }
    }
    return max1;
}