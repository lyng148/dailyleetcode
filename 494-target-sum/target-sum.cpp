class Solution {
public:
    int res = 0;

    void tryy(int index, vector<int>& nums, int target) {
        if (index == nums.size()) {
            if (target == 0) {
                res++;
            }
        } else {
            tryy(index + 1, nums, target - nums[index]);
            tryy(index + 1, nums, target + nums[index]);
        }
    }

    int findTargetSumWays(vector<int>& nums, int target) {
       

        tryy(0, nums, target);
        return res;
    }
};