bool isMonotonic(int* nums, int numsSize){
    bool asc = true;
        bool dsc = true;
        
        for (int i = 0; i < numsSize - 1; i++){
            if (!asc && !dsc) return false;
            asc = (nums[i] <= nums[i+1]) && asc;
            dsc = (nums[i] >= nums[i+1]) && dsc;
        }
        
        return asc || dsc;
}