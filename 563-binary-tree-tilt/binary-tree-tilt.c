/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void DFS(struct TreeNode* root, int* ans)
{
    if (root == NULL) return;
    DFS(root->left, ans);
    DFS(root->right, ans);
    int left = 0, right = 0;
    if (root->left != NULL) left = root->left->val;
    if (root->right != NULL) right = root->right->val;
    (*ans) += abs(left - right);
    root->val += (left + right);
}
int findTilt(struct TreeNode* root){
    int ans = 0;
    DFS(root, &ans);
    return ans;
}