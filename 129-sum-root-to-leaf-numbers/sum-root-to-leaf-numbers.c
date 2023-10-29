/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode node;
void DFS(node* root, int* ans, int *idx, int sum)
{
    if (root)
    {
        sum = sum*10 + root->val;
        if (!root->left && !root->right)
        {
            ans[(*idx)++] = sum;
            return;
        }
        DFS(root->left, ans, idx, sum);
        DFS(root->right, ans, idx, sum);
    }
}
int sumNumbers(struct TreeNode* root){
    int* ans = (int*)malloc(1001 * sizeof(int));
    memset(ans, 0, sizeof(ans));
    int idx = 0;
    DFS(root, ans, &idx, 0);
    int sum = 0;
    for (int i = 0; i < idx; i++)
    {
        sum += ans[i];
    }
    return sum;
}