/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode TreeNode;

void DFS(TreeNode *root, int low, int high, int *ans)
{
    if (root == NULL) return;
    if (low <= root->val && root->val <= high)
    {
        (*ans) += root->val;
    }
    if (root->val > low)
    {
        DFS(root->left, low, high, ans);
    }
    if (root->val < high)
    {
        DFS(root->right, low, high, ans);
    }
} 
int rangeSumBST(struct TreeNode* root, int low, int high){
    int ans = 0;
    DFS(root, low, high, &ans);
    return ans;
}