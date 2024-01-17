bool uniqueOccurrences(int* arr, int arrSize) {
    int freq[2000];
    int check[2000];
    memset(freq, 0, sizeof(freq));
    memset(check, 0, sizeof(check));
    
    for (int i = 0; i < arrSize; i++)
    {
        freq[arr[i] + 1000]++;
    }
    for (int i = 0; i < 2000; i++)
    {
        if (freq[i] != 0)
        {
           if (check[freq[i]] == 0) check[freq[i]] = 1;
           else return false;
        }
        
    }
    return true;
}