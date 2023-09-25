char findTheDifference(char * s, char * t){
    int sa[120] = {0};
    int ta[120] = {0};
    for (int i = 0; s[i] != '\0'; i++)
    {
        sa[s[i] - 'a']++;
    }
    for (int i = 0; t[i] != '\0'; i++)
    {
        ta[t[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (sa[i] != ta[i]) return i +'a';
    }
    return -1;
}