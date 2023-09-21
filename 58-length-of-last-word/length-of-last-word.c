int lengthOfLastWord(char * s){
    int last = 0;
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (count == 0 && s[i] != ' ')
        {
            count++;
        }
        else if (s[i] == ' ' && count != 0)
        {
            last = count;
            count = 0;
        }
        else if (s[i] != ' ') count++;
    }
    if (count != 0) return count; 
    return last;
}
     