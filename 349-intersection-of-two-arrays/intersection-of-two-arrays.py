class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        intersectingArray = []
        nums1.sort()
        nums2.sort()
        count1 = count2 = 0
        while (count1 < len(nums1) and count2 < len(nums2)):
            if nums1[count1] > nums2[count2]:
                count2 += 1
            elif nums1[count1] < nums2[count2]:
                count1 += 1
            else:
                sizeArrayHigh=len(intersectingArray)
                sizeArrayLow=len(intersectingArray)-1
                if not (sizeArrayHigh and nums1[count1] == intersectingArray[sizeArrayLow]):
                    intersectingArray.append(nums1[count1])
                count1 += 1
                count2 += 1

        return intersectingArray