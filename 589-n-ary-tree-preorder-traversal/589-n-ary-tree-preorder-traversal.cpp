/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root)
    {
        vector<int> ans;
        stack<Node*> st;
        if(root==NULL)
            return {};
        st.push(root);
        while(!st.empty())
        {
            Node* curr=st.top();
            st.pop();
            ans.push_back(curr->val);
            int n=curr->children.size();
            for(int i=n-1;i>=0;i--)
            {
                if(curr->children[i]!=NULL)
                    st.push(curr->children[i]);
            }
        }
        return ans;  
    }
};