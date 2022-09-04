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
    
    map<pair<int,int>,vector<int>> m; // {col,row} => vector
    // instead of map, vector of pair of ...
    
    void fill(TreeNode* root, int col, int row)
    {
        if(root==NULL)  return;
        m[{col,row}].push_back(root->val);
        fill(root->left,col-1,row+1);
        fill(root->right,col+1,row+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        fill(root,0,0);
        vector<vector<int>> ans;
        map<int,vector<int>> m2;
        for(auto &[i,j]:m) // pair,vector
        {
            sort(j.begin(),j.end());
            for(int k:j)
                m2[i.first].push_back(k);
        }
        for(auto [i,j]:m2) // col, vector
            ans.push_back(j);
        return ans;
    }
};