/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*,int> mp1;
    unordered_map<int,Node*> mp2;

public:
    Node* cloneGraph(Node* node)
    {
        if(node==NULL)
            return NULL;
        Node* head=NULL;
        if(mp1.count(node))
            return head=mp2[mp1[node]]; 
        else
        {
            head = new Node(node->val);
            mp1[node]=node->val;
            mp2[head->val]=head;
        }
        for(Node* n:node->neighbors)
            (head->neighbors).push_back(cloneGraph(n));
        return head;
    }
};