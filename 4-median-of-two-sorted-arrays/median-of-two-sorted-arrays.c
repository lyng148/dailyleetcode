//O(n+m) solution 
//binary search can reduce complexity to o(log(n+m))

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int *ans = (int*)malloc((nums1Size + nums2Size) * sizeof(int));
    int i = 0, j = 0, index = 0;
    while (i < nums1Size && j < nums2Size)
    {
        if (nums1[i] < nums2[j])
        {
            ans[index++] = nums1[i++];
        }
        else ans[index++] = nums2[j++];
    }
    while (i < nums1Size)
    {
        ans[index++] = nums1[i++];
    }
    while (j < nums2Size)
    {
        ans[index++] = nums2[j++];
    }

    if ((nums1Size + nums2Size) % 2 == 1) return ans[(nums1Size + nums2Size) / 2];
    return (double)(ans[(nums1Size + nums2Size) / 2 - 1] + ans[(nums1Size + nums2Size) / 2]) / 2;
}