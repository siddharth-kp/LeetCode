class Solution {
public:
    unordered_map<char,int> dfs(vector<int> adj[], int node, int parentNode, string& labels, vector<int>&ans)
    {
        unordered_map<char,int> child;
        unordered_map<char,int> parent;
        for(auto it: adj[node])
        {
            if(it!=parentNode)
            {
                child = dfs(adj, it, node, labels, ans);
                for(auto it: child)
                    parent[it.first] += it.second;
            }
        }
        ans[node] = ++parent[labels[node]];
        return parent;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels)
    {
        vector<int> adj[n];
        for(auto it: edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> ans(n,0);
        dfs(adj,0,-1,labels,ans);
        return ans;
    }
};