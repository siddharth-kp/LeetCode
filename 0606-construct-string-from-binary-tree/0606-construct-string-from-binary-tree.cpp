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
    string tree2str(TreeNode* root)
    {
        // if(root==NULL)
        //     return "";
        string str="";
        str += to_string(root->val);
        if(root->left!=NULL)
            str += "(" + tree2str(root->left) + ")";
        if(root->left==NULL && root->right!=NULL)
            str += "()";
        if(root->right!=NULL)
            str += "(" + tree2str(root->right) + ")";
        return str;
    }
};