class Solution {
public:
    int equalPairs(vector<vector<int>>& grid)
    {
        map<vector<int>,int> m;
        for(auto i:grid)
            m[i]++;
        int ans=0;
        for(int i=0;i<grid[0].size();i++)
        {
            vector<int> temp(grid.size());
            for(int j=0;j<grid.size();j++)
                temp[j]=grid[j][i];
            // cout<<m[temp]<<" ";
            ans+=m[temp];
        }
        return ans;
    }
};