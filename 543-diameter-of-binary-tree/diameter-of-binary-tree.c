/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode node;
int dia(node* root, int* ans)
{
    if (root == NULL)
        return 0;
    
    int leftDepth = dia(root->left, ans) + 1;
    int rightDepth = dia(root->right, ans) + 1;

    if (leftDepth + rightDepth > *ans) *ans = leftDepth + rightDepth;

    return fmax(leftDepth, rightDepth);

}

int diameterOfBinaryTree(struct TreeNode* root){
    int ans = 0;
    dia(root, &ans);
    return ans - 2;
}