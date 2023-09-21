bool canJump(int* nums, int numsSize){
    int maxReach = nums[0]; //store biggest index can reach
    int index = 0;
    while (index <= maxReach)
    {
        if (index + nums[index] > maxReach) maxReach = index + nums[index];
        if (maxReach >= numsSize - 1) return true;
        index++;
    }
    return false;
}