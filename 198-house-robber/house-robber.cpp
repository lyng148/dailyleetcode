class Solution {
public:
    int rob(vector<int>& nums) {
        int prevRob = 0;
        int maxRes = 0;
        for (int val : nums){
            int tmp = maxRes;
            maxRes = max(maxRes, prevRob + val);
            prevRob = tmp;
        }
        return maxRes;
    }
};