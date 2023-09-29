bool isMonotonic(int* nums, int numsSize){
    int stt = 0;
    if (numsSize <= 1) return true;
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] > nums[i - 1] && stt == 0)
        {
            stt = 1;
            continue;
        }
        else if (nums[i] < nums[i - 1] && stt == 0)
        {
            stt = -1;
            continue;
        }
        else if (nums[i] - nums[i - 1] > 0 && stt == -1) return false;
        else if (nums[i] - nums[i - 1] < 0 && stt == 1) return false;
    }
    return true;
}