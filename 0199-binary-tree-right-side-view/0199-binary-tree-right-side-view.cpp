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
    vector<int> rightSideView(TreeNode* root)
    {
        if(root==NULL)
            return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz=q.size();
            int value=0;
            while(sz--)
            {
                auto u=q.front();
                q.pop();
                value = (u->val);
                if(u->left!=NULL)
                    q.push(u->left);
                if(u->right!=NULL)
                    q.push(u->right);
            }
            ans.push_back(value);
        }
        return ans;
    }
};