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
    if(root)
    {
        DFS(root->left, ans, idx);
        ans[(*idx)++] = root->val;
        DFS(root->right, ans, idx);
    }
}
int kthSmallest(struct TreeNode* root, int k){
    int* ans = (int*)malloc(10001 * sizeof(int));
    int idx = 0;
    DFS(root, ans, &idx);
    return ans[k - 1];
}