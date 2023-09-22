int search(int* nums, int numsSize, int target){
    int l = 0, r = numsSize - 1;
    while (l <= r)
    {
        int mid = l + (r - l) /2;
        
        if (nums[mid] == target) return mid;
        if (nums[mid] >= nums[l])
        {
            if (nums[l] <= target && nums[mid] > target)
            {
                r = mid - 1;
            }
            else l = mid + 1;
        }
        else
        {
            if (nums[mid] < target && target <= nums[r])
            {
                l = mid + 1;
            }
            else 
            {
                r = mid - 1;
            }
        }
    }
    return -1;
}

// o day chung ta se co 2 th, va 2 th con
//ben trai hoac ben phai duoc sort
// phan tu io ben trai hoac phai
