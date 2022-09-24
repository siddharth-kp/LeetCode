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
    
    void fill(vector<vector<int>> &v, TreeNode* root, int targetSum, vector<int> path)
    {
        targetSum-=root->val;
        path.push_back(root->val);
        if(targetSum==0 && root->left==NULL && root->right==NULL)
        {
            v.push_back(path);
            return;
        }
        if(root->left!=NULL)
            fill(v,root->left,targetSum,path);
        if(root->right!=NULL)
            fill(v,root->right,targetSum,path);
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {            
        vector<vector<int>> v;
        if(root==NULL)
            return v;
        fill(v,root,targetSum,{});
        return v;
    }
};