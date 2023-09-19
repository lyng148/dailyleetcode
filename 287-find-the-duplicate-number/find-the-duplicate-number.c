int findDuplicate(int* nums, int numsSize) {
    int slow = nums[0];
    int fast = nums[0];

    // Hare and Tortoise approach to detect cycle
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // Find the entrance to the cycle
    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}
