char* removeDuplicateLetters(char* s) {
    char stack[10001];
    int top = -1;
    int count[26] = {0};
    int visited[26] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i] - 'a']++;
    }

    char* result = (char*)malloc(10001 * sizeof(char)); // Khởi tạo chuỗi kết quả

    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i] - 'a']--;

        if (visited[s[i] - 'a']) {
            continue;
        }

        while (top != -1 && stack[top] > s[i] && count[stack[top] - 'a'] > 0) {
            visited[stack[top] - 'a'] = 0;
            top--;
        }

        top++;
        stack[top] = s[i];
        visited[s[i] - 'a'] = 1;
    }

    for (int i = 0; i <= top; i++) {
        result[i] = stack[i];
    }
    result[top + 1] = '\0';

    return result;
}