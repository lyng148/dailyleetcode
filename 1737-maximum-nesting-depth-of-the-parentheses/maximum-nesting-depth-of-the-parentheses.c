int max(int a, int b){return a > b ? a : b;} 
int maxDepth(char * s){
    int stack[101];
    int top = -1;
    int max1 = -2147483648;
    int count = 0;
    int ans;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] =='(' && top == -1)
        {
            count = 1;
            stack[++top] = '(';
        }
        if (s[i] == '(' && stack[top] == '(')
        {
            count++;
            stack[++top] = '(';
            max1 = max(max1, count);
        }
        if (s[i] ==')')
        {
            count--;
            top--;
        }    
    }
    
    if (max1 > 0) return max1 - 1;
    else return 0;
}