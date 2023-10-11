#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to perform backtracking
void generateParenthesisHelper(char ***combinations, char *current, int open, int close, int max, int *count, int n) {
    if (strlen(current) == 2 * n) {
        (*combinations)[(*count)] = strdup(current); // Allocate and copy the current combination
        (*count)++;
        return;
    }

    if (open < n) {
        strcat(current, "(");
        generateParenthesisHelper(combinations, current, open + 1, close, max, count, n);
        current[strlen(current) - 1] = '\0'; // Backtrack
    }

    if (close < open) {
        strcat(current, ")");
        generateParenthesisHelper(combinations, current, open, close + 1, max, count, n);
        current[strlen(current) - 1] = '\0'; // Backtrack
    }
}

char **generateParenthesis(int n, int *returnSize) {
    *returnSize = 0; // Initialize the returnSize
    char **combinations = (char **)malloc(sizeof(char *) * 10000); // Assuming a maximum of 10000 combinations
    char *current = (char *)malloc(sizeof(char) * (2 * n + 1)); // +1 for null terminator
    current[0] = '\0'; // Initialize the current combination

    generateParenthesisHelper(&combinations, current, 0, 0, n, returnSize, n);

    free(current); // Free the memory used for the current combination
    return combinations;
}