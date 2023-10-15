/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode node;
bool check(node* root, int target)
{
    if (root == NULL) return false;
    if (root->left == NULL && root->right == NULL) return root->val == target;
    target -= root->val;
    return check(root->left, target) || check(root->right, target);
}
bool hasPathSum(struct TreeNode* root, int targetSum){
    return check(root, targetSum);
}