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
    bool levelchange=false;
    
    int fun(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        else
            return 1+fun(root->left);
    }
    
    bool checkbt(TreeNode* root, int currlevel, int &maxlevel)
    {
        if(root==NULL)
            return true; 
        if(root->left==NULL && root->right==NULL)
        {
            if(currlevel==maxlevel)
                return true;
            else if(currlevel+1==maxlevel && !levelchange)
            {
                maxlevel--;
                return levelchange=true;
            }
            else
                return false;
        }
        if(root->left==NULL && root->right!=NULL)
            return false;
        bool l=checkbt(root->left,currlevel+1,maxlevel);
        bool r=checkbt(root->right,currlevel+1,maxlevel);
        if(root->left!=NULL && root->right==NULL)
        {
            if(!levelchange)
            {
                levelchange=true;
                maxlevel--;
            }
            else
                return false;
        }
        return l&&r;
    }
    
    bool isCompleteTree(TreeNode* root)
    {
        int maxlevel=fun(root);
        return checkbt(root,1,maxlevel);
    }
};