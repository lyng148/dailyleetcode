int searchInsert(int* nums, int numsSize, int target){
    if ( target > nums[numsSize - 1]) return numsSize ;
    for( int i = 0; i < numsSize; i++){
        if (nums[i] == target) return i;
        else
        {
            if( target > nums[i] && target < nums[i+1]){
                return i + 1;
            }
        }
     
    }
    return 0;
}