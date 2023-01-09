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
    
    void pre(TreeNode* link,vector<int> &v)
    {
        if(link!=NULL)
            v.push_back(link->val);
        else
            return;
        pre(link->left,v);
        pre(link->right,v);
    }
    
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> v;
        if(root==NULL)
            return v;
        pre(root,v);
        return v;
    }
};