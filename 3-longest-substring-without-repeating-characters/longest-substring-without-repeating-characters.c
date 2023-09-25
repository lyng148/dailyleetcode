int lengthOfLongestSubstring(char * s){
    if (strcmp(s,"") == 0) return 0;
    int max = 0;
    int map[256] = {0};
    int l = 0;
    for (int r = 0; s[r] != '\0'; r++) {
        if (map[s[r]] == 0) {
            map[s[r]] = 1;
            if (r - l + 1 > max) max = r - l + 1;
        } else {
            while (s[l] != s[r]) { // l chay den khi thoat khoi thang s[r]
                map[s[l]] = 0;
                l++;
            }
            l++;
        }
    }
    return max;
}