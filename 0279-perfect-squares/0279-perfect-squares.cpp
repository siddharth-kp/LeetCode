class Solution {
private:
    vector<int> dp;
    
    int recur(int n)
    {
        if(n<0)
            return 1e5;
        if(dp[n]!=-1)
            return dp[n];
        int k=sqrt(n);
        int ans = INT_MAX;
        for(int i=k;i>=1;i--)
            ans = min(ans, 1+recur(n-i*i));
        return dp[n]=ans;
    }
    
public:
    int numSquares(int n)
    {
        dp.resize(n+1,-1);
        dp[0]=0;
        return recur(n);
    }
};