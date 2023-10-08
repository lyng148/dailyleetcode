/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root){
    if (root == NULL) return 0;
    int right = maxDepth(root->right);
    int left = maxDepth(root->left);
    return right > left ? right + 1 : left + 1;
}