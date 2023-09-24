bool isValid(char * s){
    int n = strlen(s);
    char stack[n];
    int top = -1;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stack[++top] = s[i];
        } else if (s[i] == ')' && top >= 0 && stack[top] == '(') {
            top--;
        } else if (s[i] == ']' && top >= 0 && stack[top] == '[') {
            top--;
        } else if (s[i] == '}' && top >= 0 && stack[top] == '{') {
            top--;
        } else {
            return false;
        }
    }
    
    return top == -1;
}