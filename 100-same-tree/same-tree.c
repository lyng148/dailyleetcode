/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void DFS(struct TreeNode* p, struct TreeNode* q, bool* ans)
{
    if (p == NULL && q == NULL) return;
    if (p == NULL && q != NULL){
        *ans = false;
        return;
    }
    if (p != NULL && q == NULL)
    {
        *ans = false;
        return;
    }
    if (p->val != q->val)
    {
        *ans = false;
        return;
    }
    DFS(p->left, q->left, ans);
    DFS(p->right, q->right, ans);
}
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    bool ans = true;
    DFS(p, q, &ans);
    return ans;
}