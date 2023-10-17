/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode node;

void diff(node* root, int max, int min, int* ans)
{
    if (root == NULL) return;
    if (root->val > max) max = root->val;
    if (root->val < min) min = root->val;
    if (max - min > *ans) *ans = max - min;
    diff(root->left, max, min, ans);
    diff(root->right, max, min, ans);
}

int maxAncestorDiff(struct TreeNode* root){
    int ans = 0;
    diff(root, root->val, root->val, &ans);
    return ans;
}