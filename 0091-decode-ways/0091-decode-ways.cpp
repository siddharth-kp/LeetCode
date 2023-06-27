class Solution {
public:
    
    map<string, int> mp;
    vector<int> dp;
    
    int recur(string &str, int idx)
    {
        if(idx==str.size())
            return 1;
        if(idx>str.size())
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        int ans=0;
        if(idx<str.size()-1)
        {
            if(mp.count(str.substr(idx,2)))
                ans+=recur(str,idx+2);
        }
        if(mp.count(str.substr(idx,1)))
            ans+=recur(str,idx+1);
        return dp[idx]=ans;        
    }
    
    int numDecodings(string s)
    {
        dp.resize(s.size(),-1);
        for(int i=1;i<=26;i++)
            mp[to_string(i)]=i;
        return recur(s,0);
    }
};