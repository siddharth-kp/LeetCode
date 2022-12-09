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
    
    int dfs(TreeNode* root, int mini, int maxi)
    {
        if(root==NULL)
            return maxi-mini;
        int l=-1,r=-1;
        if(root->left!=NULL)
            l=dfs(root->left,min(mini,root->left->val),max(maxi,root->left->val));
        if(root->right!=NULL)
            r=dfs(root->right,min(mini,root->right->val),max(maxi,root->right->val));
        if(l!=-1 && r!=-1)
            return max(l,r);
        else if(l==-1 && r!=-1)
            return r;
        else if(r==-1 && l!=-1)
            return l;
        else
            return max(maxi,root->val)-min(mini,root->val);
    }
    
    int maxAncestorDiff(TreeNode* root)
    {
        int maxi=root->val,mini=root->val;
        return dfs(root,mini,maxi);
    }
};