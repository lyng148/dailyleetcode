/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void DFS(struct TreeNode* root, int* ans, int* idx)
{
    if (root == NULL)
        return;
    DFS(root->left, ans, idx);
    ans[(*idx)++] = root->val;
    DFS(root->right, ans, idx);
}

int getMinimumDifference(struct TreeNode* root){
    int *ans = (int*)malloc(10001 * sizeof(int));
    int idx = 0;
    DFS(root, ans, &idx);
    int min = INT_MAX;
    for (int i = 1; i < idx; i++)
    {
        if (ans[i] - ans[i - 1] < min) min = ans[i] - ans[i - 1];
    }
    return min;
}