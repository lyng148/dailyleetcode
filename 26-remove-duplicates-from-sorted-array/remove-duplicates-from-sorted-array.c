int removeDuplicates(int* nums, int numsSize){
    int k = 1;
    int tmp = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] != tmp)
        {
            nums[k++] = nums[i];
            tmp = nums[i];
        }
        else continue;
    }
    return k;
}