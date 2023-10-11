bool isValid(int n, int *a)
{

    char stack[n];
    int top = -1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 0)
        {
            stack[++top] = a[i];
        }
        else if (a[i] == 1 && top >= 0 && stack[top] == 0)
        {
            top--;
        }
        else
        {
            return false;
        }
    }
    return top == -1;
}

void print(char** ans,int *idx, int n, int *a)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        if (a[i] == 0)
            ans[*idx][i - 1] = '(';
        else
            ans[*idx][i - 1] = ')';
    }
    ans[*idx][i - 1] = '\0';
    (*idx)++;
    // idx start at 0 which mean start also the exact number of answer
}

void try1(int i, int n, char **ans, int *idx, int *a)
{
    for (int j = 0; j <= 1; j++)
    {
        a[i] = j;
        if (i == n)
        {
            if (isValid(n, a))
                print(ans, idx, n, a);
        }
        else
            try1(i + 1, n, ans, idx, a);
    }
}

char ** generateParenthesis(int n, int* returnSize){
    int *a = (int *)malloc((n*2+1) * sizeof(int));
    char **ans = (char**)malloc(10000 * sizeof(char*));
    for (int i = 0; i < 10000; i++)
    {
        ans[i] = (char*)malloc((n*2+1) * sizeof(char));
    }
    int idx = 0;
    try1(1, n * 2, ans, &idx, a);
    *returnSize = idx;
    return ans;
}