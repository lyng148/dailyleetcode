/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rearrangeArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* numsOdd = (int*)malloc(numsSize * sizeof(int));
    int numsOddSize = 0;
    int* numsEven = (int*)malloc(numsSize * sizeof(int));
    int numsEvenSize = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] < 0)
        {
            numsOdd[numsOddSize++] = nums[i];
        }
        else numsEven[numsEvenSize++] = nums[i];
    }
    int odd = 0, even = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (i % 2 == 0)
        {
            nums[i] = numsEven[even++];
        }
        else nums[i] = numsOdd[odd++];
    }
    return nums;
}