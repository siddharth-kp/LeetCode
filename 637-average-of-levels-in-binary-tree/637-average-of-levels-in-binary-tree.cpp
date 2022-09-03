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
    vector<double> averageOfLevels(TreeNode* root)
    {
        vector<vector<TreeNode*>> level;
        queue<TreeNode*> q;
        if(root==NULL)  return {};
        q.push(root);
        while(!q.empty())
        {
            vector<TreeNode*> currlevel;
            int n = q.size();
            while(n--)
            {
                TreeNode* temp = q.front();
                q.pop();
                currlevel.push_back(temp);
                if(temp->left!=NULL)    q.push(temp->left);
                if(temp->right!=NULL)    q.push(temp->right);
            }
            level.push_back(currlevel);
        }
        vector<double> ans;
        for(int i=0;i<level.size();i++)
        {
            double sum = 0;
            for(int j=0;j<level[i].size();j++)
                sum+=(level[i][j])->val;
            sum/=level[i].size();
            ans.push_back(sum);
        }
        return ans;
    }
};