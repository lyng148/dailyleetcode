char* largestOddNumber(char* nums) {
    for (int i = strlen(nums) - 1; i >= 0; i--)
    {
        if (nums[i] == '1' || nums[i] == '3' || nums[i] == '5' || nums[i] == '7' || nums[i] == '9')
        {
            nums[i + 1] = '\0';
            return nums;
        }
    }
    return "";
}