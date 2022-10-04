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
    
    bool path(TreeNode* root, int targetSum) 
    {
        targetSum-=root->val;
        if(root->left==NULL && root->right==NULL)
        {
            if(targetSum==0)
                return true;
            else
                return false;
        }
        bool a=false, b=false;
        if(root->left!=NULL)
            a = path(root->left, targetSum);
        if(root->right!=NULL)
            b = path(root->right, targetSum);
        return a||b;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(root==NULL)
            return false;
        return path(root, targetSum);
    }
};