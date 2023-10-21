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
    DFS(root->left);
    DFS(root->right);
    struct TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    
    
}
struct TreeNode* invertTree(struct TreeNode* root){
    DFS(root);
    return root;
}