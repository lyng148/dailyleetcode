/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode node;
node* Makenode(int val)
{
  node* Newnode = (node*)malloc(sizeof(node));
  Newnode->val = val;
  Newnode->left = NULL;
  Newnode->right = NULL;
  return Newnode;
}

struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
  node* Newnode = Makenode(val);
  if (root == NULL)
  {
    root = Newnode;
    return root;
  }
  node* start = root;
  node* prev = root;
  while(root != NULL)
  {
    if (root->val < Newnode->val)
    {
      prev = root;
      root = root->right;
    }
    else if (root->val > Newnode->val)
    {
      prev = root;
      root = root->left;
    }
     
  }
  if (prev->val > Newnode->val)
     {
       prev->left = Newnode;
    
     }
     if (prev->val < Newnode->val)
     {
       prev->right = Newnode;
    
     }
    return start;
}