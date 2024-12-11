class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxRes = nums[0], curr = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++){
            curr += nums[i];
            maxRes = max(maxRes, curr);
            if (curr < 0) curr = 0;
        }
        return maxRes;
    }
};