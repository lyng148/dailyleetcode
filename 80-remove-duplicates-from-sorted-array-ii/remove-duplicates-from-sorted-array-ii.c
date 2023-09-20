int removeDuplicates(int* nums, int numsSize){
    int k = 1;
    int tmp = nums[0];
    int count = 1;
    if (numsSize == 1) return 1;
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] == tmp)
        {
            if (count <= 1)
            {
                nums[k++] = nums[i];
                count++;
            }
            else
            {
                continue;
            }
        }
        else
        {
            tmp = nums[i];
            nums[k++] = nums[i];
            count = 1;
        }
    }
    return k;
}