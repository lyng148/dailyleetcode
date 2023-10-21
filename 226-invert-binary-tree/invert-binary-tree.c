/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void DFS(struct TreeNode* root)
{
    if (root == NULL) return;
    struct TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    DFS(root->left);
    DFS(root->right);
}
struct TreeNode* invertTree(struct TreeNode* root){
    DFS(root);
    return root;
}