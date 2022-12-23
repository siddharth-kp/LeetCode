class Solution {
public:

    int fun(int i,vector<int>&prices,int signal,vector<vector<int>>&dp)
    {
        if(i>=prices.size())
            return 0;
        if(dp[i][signal]!=-1)
            return dp[i][signal];
        if(signal==1)
            return dp[i][signal] = max(-prices[i] + fun(i+1,prices,0,dp), 0 + fun(i+1,prices,1,dp));
        else
            return dp[i][signal] = max(prices[i] + fun(i+2,prices,1,dp),fun(i+1,prices,0,dp));
    }

    int maxProfit(vector<int>& prices)
    {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        int ans = fun(0,prices,1,dp);
        // for(auto i:dp)
        //     cout<<i<<" ";
        // cout << endl;
        return ans;
    }
};