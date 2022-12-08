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
    
    vector<int> v1,v2;
    
    void fill1(TreeNode* root)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)
           v1.push_back(root->val);
        fill1(root->left);
        fill1(root->right);
    }
    
    void fill2(TreeNode* root)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)
           v2.push_back(root->val);
        fill2(root->left);
        fill2(root->right);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2)
    {
        fill1(root1);
        fill2(root2);
        return v1==v2;
    }
};