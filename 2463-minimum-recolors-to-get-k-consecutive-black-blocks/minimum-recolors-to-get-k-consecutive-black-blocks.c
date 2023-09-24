int minimumRecolors(char * blocks, int k){
    //Chuoi 7 so lien tiep sao cho co it so 0 nhat
    //Ma hoa mau trang thanh 0, den thanh 1
    int count = 0;
    int min = 100;
    int l = 0, r = 0;
    for (int i = 0; i < k - 1; i++)
    {
        if (blocks[i] == 'W') count++;
    }
    for (r = k - 1; blocks[r] != '\0'; r++)
    {
        if (blocks[r] == 'W') count++;
        while ((r - l + 1) > k)
        {
            if (blocks[l] == 'W') count--;
            l++;
        }
        if (r - l + 1 == k && count < min) min = count;
    }
    return min;
}