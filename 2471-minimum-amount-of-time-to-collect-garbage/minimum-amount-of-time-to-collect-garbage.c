int garbageCollection(char** garbage, int garbageSize, int* travel, int travelSize) {
    int t[travelSize + 1];
    memset(t, 0, sizeof(t));
    for (int i = 1; i < travelSize + 1; i++)
    {
        t[i] += t[i - 1] + travel[i - 1];
    }
    int m = 0, g = 0, p = 0, ans = 0;
    for (int i = 0; i < garbageSize; i++)
    {
        ans += strlen(garbage[i]);
        for (int j = 0; garbage[i][j] != '\0'; j++)
        {
            if (garbage[i][j] == 'M') m = i;
            if (garbage[i][j] == 'P') p = i;
            if (garbage[i][j] == 'G') g = i;
        } 
    }
    ans += t[m];
    ans += t[p];
    ans += t[g];
    return ans;
}