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
    private:
    pair<int, int> solve(TreeNode* root)
    {
        if (root == NULL)
            return {INT_MIN,0};
        auto left = solve(root->left);
        auto right = solve(root->right);
        int second = root->val + max(left.second, right.second);
        if (second < 0)
            second = 0;
        int first = max(left.first, max(right.first, root->val + left.second + right.second));
        return {first, second};
    }


public:
    int maxPathSum(TreeNode* root)
    {
        return solve(root).first;
    }
};