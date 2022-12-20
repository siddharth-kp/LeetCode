class Solution {
public:
    
    void dfs(vector<vector<int>> rooms, vector<bool> &visited, int source)
    {
        if(visited[source])
            return;
        vector<int> temp=rooms[source];
        visited[source]=1;
        for(int i:temp)
            if(!visited[i])
                dfs(rooms,visited,i);
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        vector<bool> visited(rooms.size(),false);
        dfs(rooms,visited,0);
        for(int i=rooms.size()-1;i>=0;i--)
            if(!visited[i])
                return 0;
        return 1;
    }
};