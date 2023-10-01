
char * reverseWords(char * s){
    int l = 0, index = 0;
    int len = strlen(s); // Lấy chiều dài của chuỗi
    for (int i = 0; i < len; i++)
    {
        if (s[i] == ' ')
        {
            l = i - 1;
            while (index < l)
            {
                char tmp = s[index];
                s[index] = s[l];
                s[l] = tmp;
                index++;
                l--;
            }
            index = i + 1;
        }
        else if (i == len - 1)
        {
            l = i;
            while (index < l)
            {
                char tmp = s[index];
                s[index] = s[l];
                s[l] = tmp;
                index++;
                l--;
            }
        }
        
    }
    return s;
}