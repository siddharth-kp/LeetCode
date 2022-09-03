class Solution {
public:
    
    void scan(vector<vector<char>>& grid, vector<vector<bool>>& marked, int i, int j, int n, int m)
    {
        
        if(i==-1 || i==n || j==-1 || j==m)
            return;
        if(marked[i][j])
            return;
        if(grid[i][j]=='1')
            marked[i][j]=true;
        else
            return;
        scan(grid,marked,i+1,j,n,m);
        scan(grid,marked,i-1,j,n,m);
        scan(grid,marked,i,j+1,n,m);
        scan(grid,marked,i,j-1,n,m);
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size(), m=grid[0].size();
        int count = 0;
        vector<vector<bool>> marked(n,vector<bool> (m,false));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(!marked[i][j] && grid[i][j]=='1')
                {
                    count++;
                    scan(grid,marked,i,j,n,m);
                }
        return count;
    }
};