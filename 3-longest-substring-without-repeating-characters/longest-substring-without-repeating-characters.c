int lengthOfLongestSubstring(char * s) {
    if (strcmp(s,"") == 0) return 0;
    int map[400] = {0}; 
    int max = 1; // Đặt giá trị ban đầu của max là 0
    int l = 0, r = 0;
    while (s[r] != '\0') {
        if (s[r] == ' ')
        {
            r++;
            continue;
        }
        if (map[s[r]] == 0) {
            map[s[r]] = 1;
            r++;
            if (r - l > max) max = r - l;
        } else {
            map[s[l]] = 0;
            l++;
        }
    }
    return max;
}