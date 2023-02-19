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
    
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector< vector<int> > v;
        if(root==NULL)
            return v;
        queue<TreeNode*> q;
        q.push(root);
        int c=0;
        while(q.empty()==false)
        {
            vector<int> level;
            int l = q.size();
            for(int i=0;i<l;i++)
            {
                TreeNode* temp = q.front();
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
                q.pop();
                level.push_back(temp->val);
            }
            if(c%2!=0)
                reverse(level.begin(),level.end());
            //else
                //v.push_back( reverse(level) );
            v.push_back(level);
            level.clear();
            
            c++;
        }
        return v;
    }
};