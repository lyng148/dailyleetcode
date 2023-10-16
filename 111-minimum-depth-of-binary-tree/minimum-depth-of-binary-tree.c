/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int min(int a, int b){
    if (a == 1 && b == 1) return 1;
    if (a == 1 && b > 1) return b;
    if (b == 1 && a > 1) return a;
    return a < b ? a : b;
};
int minDepth(struct TreeNode* root){
    return (!root) ? 0 : min(minDepth(root->left) + 1, minDepth(root->right) + 1);
}