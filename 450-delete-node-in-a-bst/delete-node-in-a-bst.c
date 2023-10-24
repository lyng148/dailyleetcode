/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* deleteNode(struct TreeNode* root, int key){
    if (!root) return root;
    if (root)
    {
        if (root->val < key)
            root->right = deleteNode(root->right, key);
        else if (root->val > key) 
            root->left = deleteNode(root->left, key);
        /* o day, chung ta co 4 case:
        - Case 1: node can xoa la nut la => tra ve NULL de truc tiep xoa node
        - Case 2: node can xoa co node con ben trai va khong co node con ben phai => tra ve node con ben phai
        - Case 3: nguoc lai Case 2
        - Case 4; node can xoa co ca node con trai va phai
        => ta phai tim duoc node con thay the vao de dam bao thu tu theo inorder
        => ta se di tim node con lon nhat ben trai hoac node con nho nhat ben phai de the cho vao*/
        else
        {
        // case 1:
        if (!root->left && !root->right)
            return NULL;
        // case 2:
        if (!root->left && root->right)
        {
            return root->right;
        }
        // case 3:
        if (!root->right && root->left)
        {
            return root->left;
        }
        // case 4:
        struct TreeNode* tmp = root->right;
        while (tmp->left) tmp = tmp->left;
        root->val = tmp->val;
        root->right = deleteNode(root->right, root->val);
    }}
    return root;
}