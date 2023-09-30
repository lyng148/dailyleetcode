class Solution {
    public boolean find132pattern(int[] nums) {
        
        if (nums.length < 3) {
            return false;
        }
        
        int n = nums.length;
        int[] minArray = new int[n];
        minArray[0] = nums[0];
        
        for (int i = 1; i < n; i++) {
            minArray[i] = Math.min(minArray[i-1], nums[i]);
        }
        
        Stack<Integer> stack = new Stack<>();
        
        for (int i = n-1; i >= 0; i--) {
            
            while (!stack.isEmpty() && stack.peek() <= minArray[i]) {
                stack.pop();
            }
            
            if (!stack.isEmpty() && stack.peek() < nums[i]) {
                return true;
            }
            
            stack.push(nums[i]);
        }
        
        return false;
    }
}