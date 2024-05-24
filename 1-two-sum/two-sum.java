class Solution {
    public int[] twoSum(int[] nums, int target) {
       int[] res = new int[0];
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (map.get(target - nums[i]) == null) {
                map.put(nums[i], i);
            }
            else
            {
                res = new int[]{i, map.get(target - nums[i])};
            }
        }
        return res;
    }
}