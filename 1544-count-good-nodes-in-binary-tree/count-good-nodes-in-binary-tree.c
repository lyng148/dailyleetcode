/**
 * Definition for a binary tree node.
 * typedef struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode node;

void dem(node* root, int maxSinceRoot, int* count)
{
    if (root == NULL) return;
    if (root->val >= maxSinceRoot)
    {
        (*count)++;
        maxSinceRoot = root->val;
    }
    dem(root->left, maxSinceRoot, count);
    dem(root->right, maxSinceRoot, count);
}

int goodNodes(node* root)
{
    int count = 0;
    dem(root, root->val, &count);
    return count;
}