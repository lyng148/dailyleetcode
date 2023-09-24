
void merge(int *nums, int l, int r)
{
    int m = l + (r - l) / 2;
    int x = m - l + 1;
    int y = r - m;
    int a1[x], a2[y];
    for (int i = 0; i < x; i++)
    {
        a1[i] = nums[i + l];
    }
    for (int i = 0; i < y; i++)
    {
        a2[i] = nums[i + m + 1];
    }
    int idx1 = 0, idx2 = 0;
    while (idx1 < x && idx2 < y)
    {
        if (a1[idx1] < a2[idx2])
        {
            nums[l++] = a1[idx1++];
        }
        else nums[l++] = a2[idx2++];
    }
    while (idx1 < x)
    {
        nums[l++] = a1[idx1++];
    }
    while (idx2 < y)
    {
        nums[l++] = a2[idx2++];
    }
}

void merge_sort(int *nums, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        merge_sort(nums, l, m);
        merge_sort(nums, m + 1, r);
        merge(nums, l, r);
    }
}

int hIndex(int* nums, int numsSize){
    if (numsSize == 1 && nums[0] != 0) return 1;

    int count = 0;
    int max = 0, max2 = 0;
    merge_sort(nums, 0, numsSize - 1);
    for (int i = numsSize - 1; i >= 0; i--)
    {

        if (nums[i] >= numsSize - i) max = numsSize - i;
    }
   return max;
  
}