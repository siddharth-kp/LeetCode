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
    
    vector<int> v;
    
    void fill(TreeNode* root)
    {
        if(root==NULL)  return;
        v.push_back(root->val);
        fill(root->left);
        fill(root->right);
    }
    
    bool findTarget(TreeNode* root, int k)
    {
        fill(root);
        unordered_map<int,int> m;
        for(int i:v)
            if(m.count(k-i))
                return true;
            else
                m[i]++;
        return false;
    }
};