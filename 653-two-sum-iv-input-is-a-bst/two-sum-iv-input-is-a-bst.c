/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void DFS(struct TreeNode* root, int* ans, int* idx)
{
    if (root == NULL) return;
    DFS(root->left, ans, idx);
    ans[(*idx)++] = root->val;
    DFS(root->right, ans, idx);
}

bool findTarget(struct TreeNode* root, int k){

    int* ans = (int*)malloc(10001 * sizeof(int));
    int idx = 0;
    DFS(root, ans, &idx);

    int left = 0, right = idx - 1;
    while (left < right)
    {
        if (ans[left] + ans[right] == k) return true;
        if (ans[left] + ans[right] < k)
        {
            left++;
            continue;
        } 
        if (ans[left] + ans[right] > k) right--;
    }
    return false;
}