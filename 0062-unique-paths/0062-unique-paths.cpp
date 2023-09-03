class Solution {
private:
    int m,n;
    int dp[101][101];

    int recur(int x, int y)
    {
        // cout<<x<<" "<<y<<endl;
        if(x<0 || y<0 || x>=m || y>=n)
            return 0;
        if(dp[x][y]!=-1)
            return dp[x][y];
        return dp[x][y] = recur(x-1,y)+recur(x,y-1);
    }

public:
    int uniquePaths(int m, int n)
    {
        memset(dp,-1,sizeof(dp));
        dp[0][0]=1;
        for(int i=0;i<m;i++)
            dp[i][0]=1;
        for(int i=0;i<n;i++)
            dp[0][i]=1;
        this->m=m, this->n=n;
        // return 1;
        return recur(m-1,n-1);        
    }
};