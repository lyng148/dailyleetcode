
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *ans = (int *)malloc(2 * sizeof(int));
    int low = 0, high = numsSize - 1;
    int k = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            k = mid;
            high = mid - 1;
        }
        else if (nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    ans[0] = k;
    k = -1;
    low = 0;
    high = numsSize - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            k = mid;
            low = mid + 1;
        }
        else if (nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    ans[1] = k;
    return ans;
}