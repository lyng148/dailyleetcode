class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> L(nums.size(), 1);
        int n = nums.size();
        for (int i = 1; i < n; i++){
            for (int j = 0; j < i; j++){
                if (nums[i] > nums[j]){
                    L[i] = max(L[i], L[j] + 1);
                }
            }
        }
        int maxx = 0;
        for (int i = 0; i < n; i++) {
            if (L[i] > maxx) maxx = L[i]; 
        }
        return maxx;
    }
};