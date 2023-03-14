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
    
    int dig(vector<int> v)
    {
        int sum=0;
        for(int i:v)
            sum=sum*10+i;
        return sum;
    }
    
    void permute(vector<int> temp, TreeNode* root)
    {
        temp.push_back(root->val);
        if(root->left==NULL && root->right==NULL)
        {
            v.push_back(dig(temp));
            return;
        }
        if(root->left!=NULL)
            permute(temp,root->left);
        if(root->right!=NULL)
            permute(temp,root->right);
    }
    
    int sumNumbers(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        permute({},root);
        int sum=0;
        for(int i:v)
            sum+=i;
        return sum;
    }
};