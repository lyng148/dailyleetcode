int majorityElement(int* nums, int numsSize){
    int count = 1;
    int  k = nums[0];
    for (int  i = 1; i < numsSize; i++)
    {
        if (count == 0)
        {
            count = 1;
            k = nums[i];
        }
        else if (k == nums[i]) count++;
        else count--;
    } //because only major can have enough element (> n/2) so that if it subtract different num, it can still > 0
    return k;
}