class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        vector<vector<int>> paths;
        vector<int> path;
        path.push_back(0);
        for(auto& i : graph[0]) 
            bt(graph,i,path,paths);
        return paths;
    }

    void bt(vector<vector<int>>& graph,int& node , vector<int>& path , vector<vector<int>>& paths)
    {   
        path.push_back(node);
        if(node == graph.size()-1)
        {
                paths.push_back(path);
                path.pop_back();
                return;
        }
        if(graph[node].size() == 0)
        {
            path.pop_back();
            return;
        } 
        for(auto i : graph[node]) 
            bt(graph,i,path,paths);
        path.pop_back();
    }


};