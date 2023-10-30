/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
unsigned int countSetBits(unsigned int n)
{
    unsigned int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
 
int* sortByBits(int* arr, int arrSize, int* returnSize){
    int *size = (int *)malloc(arrSize * sizeof(int));
    for (int i = 0; i < arrSize; i++)
    {
        size[i] = countSetBits(arr[i]);
    }
    for (int i = 0; i < arrSize; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (size[i] < size[j])
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                tmp = size[i];
                size[i] = size[j];
                size[j] = tmp;
                continue;
            }
        }
    }
    for (int i = 0; i < arrSize; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (size[i] == size[j])
            {
                if (arr[i] < arr[j])
                {
                    int tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
            }
        }
    }
    *returnSize = arrSize;
    free(size);
    return arr;
}