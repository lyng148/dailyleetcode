class Solution {
    public int missingNumber(int[] nums) {
        int count = 0;
        int arrSize = nums.length;
        for (int i = 0; i < arrSize; i++)
        {
            count += nums[i];
        }
        return arrSize * (arrSize + 1) / 2 - count;
    }
}