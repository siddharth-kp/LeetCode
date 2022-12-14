class Solution {
public:
    
    int solve(int ind1, int ind2, vector<vector<bool>> &vis, vector<vector<int>> &grid, int count)
    {
        int n = grid.size();
        int m = grid[0].size();
        if(ind1 < 0 || ind2 < 0 || ind1 >= n || ind2 >= m || grid[ind1][ind2] == -1 || vis[ind1][ind2])
            return 0;
        if(grid[ind1][ind2] == 2)
            if(count == 0)
                return 1;
        vis[ind1][ind2] = true;
        if(grid[ind1][ind2] == 0)
        count--;
        int res = solve(ind1-1,ind2,vis,grid,count) + solve(ind1+1,ind2,vis,grid,count) + solve(ind1,ind2-1,vis,grid,count) + solve(ind1,ind2+1,vis,grid,count);
        vis[ind1][ind2] = false;
        return res;
    }
    
    
    int uniquePathsIII(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int ind1 = 0;
        int ind2 = 0;
        bool flag = false;
        for(;ind1<n;ind1++)
        {
            for(ind2=0;ind2<m;ind2++)
            {
                if(grid[ind1][ind2]==1)
                {
                    flag=true;
                    break;
                }
            }
            if(flag)
                break;
        }
        

        int count = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(grid[i][j] == 0)
                    count++;
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        return solve(ind1,ind2,vis,grid,count);
    }
};