class Solution {
private:
    unordered_map<int,int> dp;
public:
    int integerBreak(int n)
    {
        if(n<=1)
            return 1;
        if(dp.count(n))
            return dp[n];
        int ans=1;
        for(int i=1;i<n;i++)
        {
            ans=max(max(ans,i*(n-i)),i*integerBreak(n-i));
        }
        return dp[n]=ans;
    }
};