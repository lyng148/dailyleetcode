/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void DFS(struct TreeNode* root1, struct TreeNode* root2, bool* ans)
{
    if (root1 == NULL && root2 == NULL) return;
    if (root1 != NULL & root2 == NULL )
    {
        (*ans) = false;
        return;
    }
    if (root1 == NULL & root2 != NULL )
    {
        (*ans) = false;
        return;
    }
    DFS(root1->left, root2->right, ans);
    if (root1->val != root2->val){
        *ans = false;
        return;
    } 
    DFS(root1->right, root2->left, ans);
}
bool isSymmetric(struct TreeNode* root){
    bool ans = true;
    DFS(root, root, &ans);
    return ans;
}