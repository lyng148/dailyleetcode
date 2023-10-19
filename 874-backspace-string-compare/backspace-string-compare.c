bool backspaceCompare(char * s, char * t){
    char S1[201] = {0};
    int topS1 = -1;
    char S2[201] = {0};
    int topS2 = -1;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != '#') S1[++topS1] = s[i];
        else
        {
            topS1--;
            if (topS1 < -1) topS1 = -1;
        }
    }
    for (int i = 0; t[i] != '\0'; i++)
    {
        if (t[i] != '#') S2[++topS2] = t[i];
        else
        {
            topS2--;
            if (topS2 < -1) topS2 = -1;
        }
    }
    if (topS1 != topS2) return false;
    for (int i = 0; i <= topS1; i++)
    {
        if (S1[i] != S2[i]) return false;
    }
    return true;
}