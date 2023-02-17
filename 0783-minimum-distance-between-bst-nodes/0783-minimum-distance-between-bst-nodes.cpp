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
    void fun(TreeNode* root, int &mini, int &prev)
    {
        if(root==nullptr)
            return;
        fun(root->left, mini, prev);
        if (prev!=-1)
            mini=min(mini, root->val-prev);
        prev=root->val;
        fun(root->right, mini, prev);
    }
    
    
    int minDiffInBST(TreeNode* root)
    {
        int mini=INT_MAX, prev=-1;
        fun(root,mini,prev);
        return mini;
    }
};