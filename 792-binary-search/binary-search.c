int bssearch(int *nums, int l, int r, int target) {
    if (l <= r) {
        int m = l + (r - l) / 2;
        if (nums[m] == target) return m;
        else if (nums[m] < target) return bssearch(nums, m + 1, r, target);
        else return bssearch(nums, l, m - 1, target);
    }
    return -1;
}

int search(int* nums, int numsSize, int target){
    return bssearch(nums, 0, numsSize - 1, target);
}