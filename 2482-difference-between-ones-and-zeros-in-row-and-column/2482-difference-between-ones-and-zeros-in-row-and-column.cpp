class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid)
    {
        vector<int> rowsum(grid.size(),0), colsum(grid[0].size(),0);
        for(int i=0;i<grid.size();i++)
            for(int j:grid[i])
                rowsum[i]+=j;
        for(int i=0;i<grid[0].size();i++)
            for(int j=0;j<grid.size();j++)
                colsum[i]+=grid[j][i];
        vector<vector<int>> ans(grid.size(), vector<int>(grid[0].size()));
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                ans[i][j]=2*rowsum[i] + 2*colsum[j] - grid.size() - grid[0].size();
        return ans;
    }
};