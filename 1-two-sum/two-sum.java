class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int numsSize = nums.length;
        int[] ans = new int[2];
        for (int i = 0; i < numsSize; i++)
        {
            if (map.containsKey(target - nums[i]))
            {
                ans[0] = map.get(target - nums[i]);
                ans[1] = i;
                return ans;
            }
            else map.put(nums[i], i);
        }
        return ans;
    }
}