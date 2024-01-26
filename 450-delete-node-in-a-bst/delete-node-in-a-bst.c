/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* deleteNode(struct TreeNode* root, int key){
    if (root == NULL)
        return NULL;
    else if (root->val < key)
        root->right = deleteNode(root->right, key);
    else if (root->val > key)
        root->left = deleteNode(root->left, key);
    else
    {
        if (!root->left && !root->right)
            return NULL;
        else if (!root->left && root->right)
            return root->right;
        else if (root->left && !root->right)
            return root->left;
        else
        {
            struct TreeNode *tmp = root->right;
            while (tmp->left != NULL)
                tmp = tmp->left;
            root->val = tmp->val;
            root->right = deleteNode(root->right, root->val);
        }
    } 
    return root;
}