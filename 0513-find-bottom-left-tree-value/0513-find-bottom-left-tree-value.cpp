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
    int findBottomLeftValue(TreeNode* root)
    {
        int ans = root->val;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz=q.size();
            int begin=1;
            while(sz--)
            {
                auto u = q.front();
                q.pop();
                if(begin)
                {
                    ans=u->val;
                    begin=0;
                }
                if(u->left!=NULL)
                    q.push(u->left);
                if(u->right!=NULL)
                    q.push(u->right);
            }
        }
        return ans;
    }
};