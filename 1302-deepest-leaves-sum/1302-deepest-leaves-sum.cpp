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
    
    unordered_map<int,int> m;
    
    void fill(TreeNode* root, int level)
    {
        if(root==NULL)  return;
        m[level]+=root->val;
        fill(root->left,level+1);
        fill(root->right,level+1);
    }
    
    int deepestLeavesSum(TreeNode* root)
    {
        fill(root,1);
        int maxi=INT_MIN,val=0;
        for(auto i:m)
            if(i.first>maxi)
            {
                maxi=i.first;
                val=i.second;
            }
        return val;
    }
};