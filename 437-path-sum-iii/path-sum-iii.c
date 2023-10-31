/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode node;

void DFS(node* root, long long target, int* ans)
{
    if (root)
    {
        target -= root->val;
        if (target == 0)
        {
            *ans += 1; 
        }
        DFS(root->left, target, ans);
        DFS(root->right, target, ans);
    }
}

void check(node* root, long long target, int* ans)
{
  if (root)
  {
    DFS(root, target, ans);
    check(root->left, target, ans);
    check(root->right, target, ans);
  }
}
int pathSum(struct TreeNode* root, int targetSum){
  int ans = 0;
  check(root, targetSum, &ans);
  return ans;
}