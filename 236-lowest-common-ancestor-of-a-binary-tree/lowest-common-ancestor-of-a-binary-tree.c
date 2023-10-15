/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL) {
            return NULL;
        }
        
        // first case
        if (root == p || root == q) {
            return root;
        }
        
        struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
        struct TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        // second case
        if (left != NULL && right != NULL) {
            return root;
        }
        
        // third case
        if (left != NULL) {
            return left;
        }
        
        return right;
}