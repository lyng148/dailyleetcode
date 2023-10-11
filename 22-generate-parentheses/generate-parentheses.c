#include <stdio.h>
#include <stdlib.h>

bool isValid(int n, int *a) {
    int balance = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            balance++;
        } else {
            balance--;
        }
        if (balance < 0) {
            return false;
        }
    }
    return balance == 0;
}

void print(char **ans, int *idx, int n, int *a) {
    int i;
    for (i = 1; i <= n; i++) {
        if (a[i] == 0)
            ans[*idx][i - 1] = '(';
        else
            ans[*idx][i - 1] = ')';
    }
    ans[*idx][i - 1] = '\0'; // Thay đổi dòng này từ ans[*idx][i] thành ans[*idx][i - 1]
    (*idx)++;
}

void try1(int i, int n, char **ans, int *idx, int *a) {
    if (i > n) {
        if (isValid(n, a)) {
            print(ans, idx, n, a);
        }
        return;
    }

    for (int j = 0; j <= 1; j++) {
        a[i] = j;
        try1(i + 1, n, ans, idx, a);
    }
}

char **generateParenthesis(int n, int *returnSize) {
    int *a = (int *)malloc((2 * n + 1) * sizeof(int));
    char **ans = (char **)malloc(10000 * sizeof(char *));
    for (int i = 0; i < 10000; i++) {
        ans[i] = (char *)malloc((2 * n + 1) * sizeof(char));
    }
    int idx = 0;
    try1(1, 2 * n, ans, &idx, a);
    *returnSize = idx;
    return ans;
}
