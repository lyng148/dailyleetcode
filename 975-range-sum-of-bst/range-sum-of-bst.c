/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode TreeNode;

void DFS(TreeNode *root, int low, int high, int *ans)
{
    if (root == NULL) return;
    if (low <= root->val && root->val <= high)
    {
        (*ans) += root->val;
    }
    if (root->val > low) // o day sai vi minh dang nghi neu sai thi chi duyet o ben kia
    {                    // nhung ma truong hop dung no bo qua hettttttt
        DFS(root->left, low, high, ans); // can doi cach tu duy, nhu kieu dung thi moi duyet tiep, khong phai la sai thi doi
    }
    if (root->val < high)
    {
        DFS(root->right, low, high, ans);
    }
} 
int rangeSumBST(struct TreeNode* root, int low, int high){
    int ans = 0;
    DFS(root, low, high, &ans);
    return ans;
}