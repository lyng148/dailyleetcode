int cmpfunc(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}

int* targetIndices(int* nums, int numsSize, int target, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    int* ans = (int*)malloc(numsSize * sizeof(int));
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            ans[count++] = i;
        }
    }

    *returnSize = count;
    return ans;
}