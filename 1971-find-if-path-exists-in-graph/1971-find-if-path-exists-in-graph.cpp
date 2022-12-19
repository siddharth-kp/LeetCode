// class Solution {
// public:
    
//     map<int,vector<int>> m;
    
//     bool dfs(int source, int destination, vector<bool> &visited)
//     {
//         visited[source]=true;
//         //cout<<source<<endl;
//         if(source==destination)
//             return true;
//         for(auto i:m[source])
//             if(!visited[i])
//                if(dfs(i,destination,visited)) // instead of return dfs(i,destination,visited), use this
//                    return true;
//         return false;
//     }
    
//     bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
//     {
//         for(auto i:edges)
//         {
//             m[i[0]].push_back(i[1]);
//             m[i[1]].push_back(i[0]);
//         }
//         vector<bool> visited(n,false);
//         bool a = dfs(source,destination,visited);
//         return visited[destination];
//     }
// };


class Solution {
public:
    
    bool dfs(vector<vector<int>>& graph, vector<int>& visited, int current, int end)
    {
        if(current == end)
            return true;
        if(visited[current])
            return false;
        visited[current] = 1;
        for(int i=0; i<graph[current].size(); i++)
        {
            if(dfs(graph, visited, graph[current][i], end))
                return true;
        }
        
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int end)
    {
        vector<vector<int>> graph(n);
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(n,0);
        return dfs(graph,visited,start,end);
    }
};