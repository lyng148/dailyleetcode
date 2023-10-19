/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int depth(struct TreeNode* root, bool* ans)
{
    if (root == NULL) return 0;
    int leftDepth = depth(root->left, ans) + 1;
    int rightDepth = depth(root->right, ans) + 1;
    if (abs(rightDepth - leftDepth) > 1) *ans = false;
    return fmax(leftDepth, rightDepth);
}
bool isBalanced(struct TreeNode* root){
    if (root == NULL) return true;
    bool ans = true;
    depth(root, &ans);
    return ans;
}