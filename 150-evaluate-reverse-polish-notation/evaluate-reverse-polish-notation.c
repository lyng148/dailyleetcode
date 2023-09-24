int evalRPN(char ** s, int tokensSize){
    int stack[10000];
    int top = -1;
    for (int i = 0; i < tokensSize; i++)
    {
        if (strcmp(s[i], "+") != 0 && strcmp(s[i], "-") != 0 && strcmp(s[i], "*") != 0 && strcmp(s[i], "/") != 0)
        {
            stack[++top] = atoi(s[i]);
        }
        else
        {
            if (strcmp(s[i], "+") == 0)
            {
                int a = stack[top--];
                int b = stack[top--];
                stack[++top] = a + b;
            }
            if (strcmp(s[i], "-") == 0)
            {
                int b = stack[top--];
                int a = stack[top--];
                stack[++top] = a - b;
            }
            if (strcmp(s[i], "*") == 0)
            {
                int b = stack[top--];
                int a = stack[top--];
                stack[++top] = a * b;
            }
            if (strcmp(s[i], "/") == 0)
            {
                int b = stack[top--];
                int a = stack[top--];
                stack[++top] = a / b;
            }
        }
    }
    return stack[top];
}