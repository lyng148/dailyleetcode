void swap(int *a, int *b){int tmp = *a; *a = *b; *b = tmp;}

int* sortArrayByParity(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int i = 0;
    for (int j = 0; j < numsSize; j++)
    {
        if (nums[j] % 2 == 0)
        {
            swap(&nums[i], &nums[j]);
            i++;
        }
    }
    return nums;
}