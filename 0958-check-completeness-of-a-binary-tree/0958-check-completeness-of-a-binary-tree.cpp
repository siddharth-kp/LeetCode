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
    
    int countnodes(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return 1+countnodes(root->left)+countnodes(root->right);
    }
    
    bool checkbt(TreeNode* root, int curr, int n)
    {
        if(root==NULL)
            return true;
        if(curr>n)
            return false;
        return checkbt(root->left,curr*2,n) && checkbt(root->right,curr*2+1,n);
    }
    
    bool isCompleteTree(TreeNode* root)
    {
        if(root==NULL)
            return true;
        int n=countnodes(root);
        return checkbt(root,1,n);
    }
};