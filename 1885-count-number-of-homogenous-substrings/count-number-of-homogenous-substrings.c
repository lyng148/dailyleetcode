long long tong(long long a)
{
    if (a == 1) return 1;
    return (a + 1) * a / 2;
}

int countHomogenous(char * s){
    int mod = 1e9 + 7;
    int ans = 0;
    int freq = 1;
    char prev = s[0];
    if(strlen(s) == 1) return 1;
    for (int i = 1; s[i] != '\0'; i++)
    {
        if (s[i] == prev) freq++;
        else
        {
            ans = (long long)(ans + tong(freq)) % mod;
            freq = 1;
            prev = s[i];
        }
    }
    ans = (long long)(ans + tong(freq)) % mod;
    return ans;
}