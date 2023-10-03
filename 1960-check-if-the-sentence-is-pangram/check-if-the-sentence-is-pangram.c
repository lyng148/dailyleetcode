bool checkIfPangram(char * s){
    int alpha[26] = {0};
    for (int i = 0; s[i] != '\0'; i++)
    {
        alpha[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (alpha[i] == 0) return false;
    }
    return true;
}