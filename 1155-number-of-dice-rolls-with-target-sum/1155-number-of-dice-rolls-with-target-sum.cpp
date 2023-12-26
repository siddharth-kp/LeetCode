class Solution {
private:
    int mod=1e9+7;
    vector<vector<int>> dp;

    int recur(int target, int n, int k)
    {
        // cout<<target<<" "<<n<<" "<<k<<endl;
        if(n==0 & target==0)
            return 1;
        if(n==0 || target<=0)
            return 0;
        if(dp[target][n]!=-1)
            return dp[target][n];
        int ans=0;
        for(int i=1;i<=k;i++)
        {
            ans+=recur(target-i,n-1,k);
            ans%=mod;
        }
        return dp[target][n]=ans;
    }
public:
    int numRollsToTarget(int n, int k, int target)
    {
        dp.resize(target+1,vector<int> (n+1,-1));
        return recur(target,n,k)%mod;
    }
};