class Solution {
private:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        if(vis[i][j]) return 0;
        vis[i][j] = 1;
        int delx[] = {0, -1, 0, +1};
        int dely[] = {+1, 0, -1, 0};
        int ret = 1;
        for(int k=0; k<4; k++) {
            if(i+delx[k]>=0 && i+delx[k]<grid.size() && j+dely[k]>=0 && j+dely[k]<grid[0].size() && grid[i+delx[k]][j+dely[k]] && !vis[i+delx[k]][j+dely[k]]) {
                ret+=dfs(i+delx[k], j+dely[k], grid, vis);
            }
        }
        return ret;
    }
    // int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis)
    // {
    //     if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size())
    //         return 0;
    //     if(vis[i][j])
    //         return 0;
    //     vis[i][j]=1;
    //     int left = dfs(i,j-1,grid,vis);
    //     int right = dfs(i,j+1,grid,vis);
    //     int up = dfs(i-1,j,grid,vis);
    //     int down = dfs(i+1,j,grid,vis);
    //     return 1+left+right+up+down;
    // }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        // queue<pair<int, int>>q;
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), 0));
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(grid[i][j] && !vis[i][j]) {
                    ans = max(ans, dfs(i, j, grid, vis));
                }
                // if(grid[i][j] && !vis[i][j]) {
                //     vis[i][j] = 1;
                //     q.push({i, j});
                //     int temp_ans = 0;
                //     while(!q.empty()) {
                //         int x = q.front().first;
                //         int y = q.front().second;
                //         q.pop();
                //         temp_ans++;

                //         int delx[] = {0, -1, 0, +1};
                //         int dely[] = {+1, 0, -1, 0};
                //         for(int k=0; k<4; k++) {
                //             if(x+delx[k]>=0 && x+delx[k]<grid.size() && y+dely[k]>=0 && y+dely[k]<grid[0].size() && grid[x+delx[k]][y+dely[k]] && !vis[x+delx[k]][y+dely[k]]) {
                //                 vis[x+delx[k]][y+dely[k]] = 1;
                //                 q.push({x+delx[k], y+dely[k]});
                //             }
                //         }
                //     }
                //     ans = max(ans, temp_ans);
                // }
            }
        }
        return ans;  
    }
};