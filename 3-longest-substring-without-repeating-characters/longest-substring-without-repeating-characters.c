int lengthOfLongestSubstring(char *s) {
    if (strcmp(s, "") == 0) return 0;
    int max = 0;
    int map[256] = {0}; // Sửa thành 256 vì ASCII có 256 ký tự
    int l = 0;
    int r = 0;

    while (s[r] != '\0') {
        if (map[s[r]] == 0) {
            map[s[r]] = 1;
            if (r - l + 1 > max) max = r - l + 1;
            r++;
        } else {
            map[s[l]] = 0;
            l++;
        }
    }
    return max;
}
