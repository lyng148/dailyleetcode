//O(n+m) solution 
//binary search can reduce complexity to o(log(n+m))

//Mean of an array = (sum of all elements) / (number of elements)

//The median of a sorted array of size N is defined as the middle element when N is odd and average of middle
//two elements when N is even. Since the array is not sorted here, we sort the array first, then apply above
//formula.
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