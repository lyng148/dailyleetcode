class Solution:
    def maximumScore(self, nums: List[int], k: int) -> int:
        n = len(nums)
        result = 0

        for left in range(k - 1, -1, -1):
            nums[left] = min(nums[left], nums[left + 1])
        for right in range(k + 1, n):
            nums[right] = min(nums[right], nums[right - 1])

        right = k + 1
        for left in range(k, -1, -1):
            while right < n and nums[right] >= nums[left]:
                right += 1
            result = max(result, nums[left] * (right - left))

        left = k - 1
        for right in range(k, n):
            while left >= 0 and nums[left] >= nums[right]:
                left -= 1
            result = max(result, nums[right] * (right - left))

        return result