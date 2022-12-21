class Solution {
public:
    int bfs(int start,vector<int>&vis,vector<int>adj[])
    {
        vis[start]=1;
        queue<int>q;
        q.push(start);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:adj[node])
            {
                if(vis[it]==vis[node])
                    return 1;
                if(!vis[it])
                {
                    vis[it]=-vis[node];
                    q.push(it);
                }
            }
        }
        return 0;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes)
    {
        vector<int>adj[n+1];
        for(int i=0;i<dislikes.size();i++)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);   
        }
        vector<int>vis(n+1,0);
        for(int i=1;i<=n;i++)
            if(!vis[i])
                if(bfs(i,vis,adj)==1)
                    return false;
       return true;
    }
};