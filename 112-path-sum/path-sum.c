/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode node;
void DFS(node* root, int target, bool* check)
{
    if (root)
    {
        target -= root->val;
        if (target == 0 && !root->left && !root->right)
        {
            *check = true;
            return;
        }
        DFS(root->left, target, check);
        DFS(root->right, target, check);
    }
}
bool hasPathSum(struct TreeNode* root, int targetSum){
    bool check = false;
    DFS(root, targetSum, &check);
    return check;
}