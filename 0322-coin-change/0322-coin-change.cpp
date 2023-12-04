#define ll int64_t

class Solution {
private:
    vector<int> coins;
    unordered_map<ll,ll> dp;
    
    ll recur(ll amount)
    {
        if(amount<0)
            return INT_MAX;
        if(amount==0)
            return 0;
        if(dp.count(amount))
            return dp[amount];
        ll ans=INT_MAX;
        for(int i=0;i<coins.size();i++)
            ans=min(ans, 1+recur(amount-coins[i]));
        return dp[amount]=ans;
    }
    
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        this->coins=coins;
        ll ans = recur(amount);
        // for(auto [i,j]:dp)
        //     cout<<i<<" "<<j<<endl;
        return ans==INT_MAX?-1:ans;
    }
};