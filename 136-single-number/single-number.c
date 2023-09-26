int singleNumber(int* nums, int numsSize){
    //XOR applied
    int a = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        a ^= nums[i];
    }
    return a;
}