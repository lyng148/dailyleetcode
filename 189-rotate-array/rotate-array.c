void rotate(int* nums, int numsSize, int k){
    int *a = (int *)malloc(numsSize * sizeof(int));
    int index = 0;
    while (k > numsSize) k-= numsSize;
    for (int i = numsSize - k; i < numsSize; i++)
    {
        a[index++] = nums[i];
    }
    for (int i = 0; i < numsSize - k; i++)
    {
        a[index++] = nums[i];
    }
    for (int i = 0; i < numsSize; i++)
    {
        nums[i] = a[i];
    }
    free(a);
}