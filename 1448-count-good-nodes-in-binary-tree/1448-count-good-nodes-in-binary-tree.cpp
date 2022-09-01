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
    
    int count(TreeNode* root, int currmax)
    {
        if(root==NULL)
            return 0;
        int valid=0;
        if(root->val>=currmax)
        {
            currmax=root->val;
            valid=1;
        }
        return valid+count(root->left,currmax)+count(root->right,currmax);
    }
    
    int goodNodes(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return count(root,root->val);
    }
};