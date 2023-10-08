int max(int a, int b){return a > b ? a : b;};
int maxDepth(struct TreeNode* root){
    return (!root) ? 0 : max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
}