int cmpfunc(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}

int* targetIndices(int* nums, int numsSize, int target, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    int l = 0, r = numsSize - 1;
    int* ans = (int*)malloc(numsSize * sizeof(int));
    int count = 0;
    int index = 0;
    
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (nums[m] == target) {
            index = m;
            r = m - 1;
        } else if (nums[m] < target) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    for (int i = index; i < numsSize; i++)
    {
        if (nums[i] == target)
        {
            ans[count++] = i;
        }
    }
    *returnSize = count;
    return ans;
}
