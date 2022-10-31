class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>visited(n,vector<vector<int>>(m,vector<int>(k+1,0)));
        queue<pair<pair<int,int>,pair<int,int>>>q;
        if(grid[0][0]==0)
        q.push({{0,0},{k,1}});
        else{
            if(k==0)
                return -1;
            q.push({{0,0},{k-1,1}});
        }
        int minsteps=INT_MAX;
        // visited[0][0][k]=1;
        while(!q.empty())
        {   
            
            pair<pair<int,int>,pair<int,int>>temp=q.front();
            q.pop();
            if(temp.first.first==n-1 and temp.first.second==m-1)
            {
                minsteps=min(minsteps,temp.second.second);
                break;
            }
            else{
                int left=temp.second.first;
                int x=temp.first.first;
                int y=temp.first.second;
                int steps=temp.second.second;
                if(x-1>=0 and grid[x-1][y]==0 and visited[x-1][y][left]==0)
                {
                    visited[x-1][y][left]=1;
                    q.push({{x-1,y},{left,steps+1}});
                }
                 if(y+1<m and grid[x][y+1]==0 and visited[x][y+1][left]==0)
                {
                    visited[x][y+1][left]=1;
                    q.push({{x,y+1},{left,steps+1}});
                }
                if(x+1<n and grid[x+1][y]==0 and visited[x+1][y][left]==0)
                {
                    visited[x+1][y][left]=1;
                    q.push({{x+1,y},{left,steps+1}});
                }
                if(y-1>=0 and grid[x][y-1]==0 and visited[x][y-1][left]==0)
                {
                    visited[x][y-1][left]=1;
                    q.push({{x,y-1},{left,steps+1}});
                }
                if(x+1<n  and left>0 and grid[x+1][y]==1 and visited[x+1][y][left-1]==0)
                {
                    visited[x+1][y][left-1]=1;
                    q.push({{x+1,y},{left-1,steps+1}});
                }
                if(y-1>=0 and left>0  and grid[x][y-1]==1 and visited[x][y-1][left-1]==0)
                {
                    visited[x][y-1][left-1]=1;
                    q.push({{x,y-1},{left-1,steps+1}});
                }
                 if(x-1>=0 and left>0  and grid[x-1][y]==1 and visited[x-1][y][left-1]==0)
                {
                    visited[x-1][y][left-1]=1;
                    q.push({{x-1,y},{left-1,steps+1}});
                }
                if(y+1<m  and left>0 and grid[x][y+1]==1 and visited[x][y+1][left-1]==0)
                {
                    visited[x][y+1][left-1]=1;
                    q.push({{x,y+1},{left-1,steps+1}});
                }
                
                
            }
            
        }
        
        return minsteps==INT_MAX?-1:minsteps-1;
        
        
    }
};