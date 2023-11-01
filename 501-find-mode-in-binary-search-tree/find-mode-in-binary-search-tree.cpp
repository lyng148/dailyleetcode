/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> freq;
        int maxFreq = 1;
        vector<int> modes;
        dfs(root, freq, maxFreq);
        for(auto& [val, cnt] : freq)
            if(cnt == maxFreq)
                modes.push_back(val);
        return modes;
    }
    void dfs(TreeNode* root, unordered_map<int, int>& freq, int& maxFreq){
        if(root != nullptr) {
            freq[root->val]++;
            maxFreq = max(maxFreq, freq[root->val]);
            for(auto& child : {root->left, root->right}) {
                if(child)
                    dfs(child, freq, maxFreq);
            }
        }
    }
};