class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m = obstacleGrid.size(), n=obstacleGrid[0].size();
        int dp[m][n];
        bool f = false;
        for(int i=0;i<m;i++)
        {
            if(obstacleGrid[i][0])
                f=true;
            dp[i][0]=!f;
        }
        f=false;
        for(int i=0;i<n;i++)
        {
            if(obstacleGrid[0][i])
                f=true;
            dp[0][i]=!f;
        }
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                dp[i][j]=obstacleGrid[i][j]?0:dp[i-1][j]+dp[i][j-1];
        return dp[m-1][n-1];
    }
};