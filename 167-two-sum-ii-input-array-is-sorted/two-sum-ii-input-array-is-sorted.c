/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int* c = (int*)malloc(2 * sizeof(int));
    int l = 0;
    int r = numbersSize - 1;
    while (l < r){
        if (numbers[l] + numbers[r] < target) l++;
        else if (numbers[l] + numbers[r] > target) r--;
        else
        {
            c[0] = l + 1;
            c[1] = r + 1;
            break;
        }
    }
    *returnSize = 2;
    return c;
}