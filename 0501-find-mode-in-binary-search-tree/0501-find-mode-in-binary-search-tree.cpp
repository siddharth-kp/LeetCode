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
    
    void fill(TreeNode* root, map<int,int> &m)
    {
        if(root==NULL)
            return;
        m[root->val]++;
        fill(root->left,m);
        fill(root->right,m);
    }
    
    vector<int> findMode(TreeNode* root) 
    {
        map<int,int> m;
        fill(root,m);
        vector<pair<int,int>> v;
        // for(auto i:m)
        //     cout<<i.first<<" "<<i.second<<endl;
        for(auto i:m)
            v.push_back({i.second,i.first});
        sort(v.begin(),v.end());
        vector<int> v2;
        int l = v.size();
        v2.push_back(v[l-1].second);
        for(int i=l-2;i>=0;i--)
            if(v[i].first<v[i+1].first)
                break;
            else
                v2.push_back(v[i].second);
        return v2;
    }
};