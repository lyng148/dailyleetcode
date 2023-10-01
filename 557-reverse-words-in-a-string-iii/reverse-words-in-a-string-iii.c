
char * reverseWords(char * s){
    int l = 0, index = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if (s[i + 1] == ' ' || i == len - 1)
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
            index = i + 2;
        }
    }
    return s;
}