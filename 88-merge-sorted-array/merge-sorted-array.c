void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int index = nums1Size - 1;
    int i = m - 1;
    int j = n - 1;
  

    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[index--] = nums1[i--];
        }
        else nums1[index--] = nums2[j--];
    }
    while (j >= 0) nums1[index--] = nums2[j--]; 

    return; 
}