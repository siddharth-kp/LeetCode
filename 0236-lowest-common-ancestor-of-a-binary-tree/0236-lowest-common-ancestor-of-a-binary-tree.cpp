/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    pair<bool, TreeNode*> found(TreeNode* node, TreeNode* p, TreeNode* q)  {
        if(node==NULL) return {false, NULL};
        
        pair<bool, TreeNode*> left = found(node->left, p, q);
        pair<bool, TreeNode*> right = found(node->right, p, q);
        if(left.second || right.second) {
            return {true, left.second!=NULL ? left.second: right.second};
        } else if(left.first && right.first) {
            return {true, node};
        } else if(left.first || right.first) {
            if(node==p||node==q) return {true, node};
            else return {true, NULL};
        } else if(node==p||node==q) return {true, NULL};
        
        return {false, NULL};

        
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return found(root, p, q).second;
    }
};