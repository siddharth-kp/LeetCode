// class Solution {
// public:
    
//     void dfs(vector<vector<int>> rooms, vector<bool> &visited, int source)
//     {
//         if(visited[source])
//             return;
//         vector<int> temp=rooms[source];
//         visited[source]=1;
//         for(int i:temp)
//             if(!visited[i])
//                 dfs(rooms,visited,i);
//     }
    
//     bool canVisitAllRooms(vector<vector<int>>& rooms)
//     {
//         vector<bool> visited(rooms.size(),false);
//         dfs(rooms,visited,0);
//         for(int i=rooms.size()-1;i>=0;i--)
//             if(!visited[i])
//                 return 0;
//         return 1;
//     }
// };



// BFS solution

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        vector<bool> vis(rooms.size(),0);
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            int s = q.size();
            for(int i=0;i<s;i++)
            {
                int curr = q.front();
                q.pop();
                for(int keys : rooms[curr])
                {
                    if(!vis[keys])
                    {
                        q.push(keys);
                        vis[keys] = 1;
                    }
                }
            }
        }
        for(auto x: vis) if(!x) return 0;
        return 1;
    }
};