//  dp[row][col][moves_left] = no of ways to go out from (row,col)

class Solution {
private:
    int dp[50][50][51];
    int mod = 1e9+7;
    int m,n;
    
    int recur(int row, int col, int moves)
    {

        if(row<0 || row>=m || col<0 || col>=n)
            return 1;
        if(moves<=0)
            return 0;
        if(dp[row][col][moves]!=-1)
            return dp[row][col][moves];
        int up = recur(row-1,col,moves-1)%mod;
        int down = recur(row+1,col,moves-1)%mod;
        int left = recur(row,col-1,moves-1)%mod;
        int right = recur(row,col+1,moves-1)%mod;
        return dp[row][col][moves]=((left+right)%mod+(up+down)%mod)%mod;
    }
    
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        this->m=m, this->n=n;
        memset(dp,-1,sizeof(dp));
        return recur(startRow,startColumn,maxMove);
    }
};