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
    bool leftCheck, rightCheck;

    if (root == NULL) 
        return false;

    if (root->right == NULL && root->left == NULL) //root is a leaf
    {
        return root->val == target;
    }

    target -= root ->val;

    leftCheck = check(root->left, target);
    rightCheck = check(root->right, target);
    return (leftCheck || rightCheck);
} 
bool hasPathSum(node* root, int targetSum){
    return check(root, targetSum);
}