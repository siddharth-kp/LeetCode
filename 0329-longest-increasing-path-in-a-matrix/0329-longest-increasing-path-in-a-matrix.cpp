class Solution {
private:
    vector<vector<int>> dp;
    vector<vector<int>> matrix;
    
    int recur(int row, int col)
    {
        int ans=1;
        if(dp[row][col]!=-1)
            return dp[row][col];
        if(row!=0 && matrix[row-1][col]>matrix[row][col])
            ans=max(ans,1+recur(row-1,col));
        if(row!=matrix.size()-1 && matrix[row+1][col]>matrix[row][col])
            ans=max(ans,1+recur(row+1,col));
        if(col!=0 && matrix[row][col-1]>matrix[row][col])
            ans=max(ans,1+recur(row,col-1));
        if(col!=matrix[0].size()-1 && matrix[row][col+1]>matrix[row][col])
            ans=max(ans,1+recur(row,col+1));
        return dp[row][col]=ans;
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        this->matrix=matrix;
        dp.resize(matrix.size(),vector<int>(matrix[0].size(),-1));
        int ans=0;
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[0].size();j++)
                ans=max(ans,recur(i,j));
        return ans;
    }
};