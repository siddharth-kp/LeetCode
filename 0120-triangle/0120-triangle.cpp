class Solution {
public:
    
    vector<vector<int>> dp;
    
    int recur(vector<vector<int>> &triangle, int level, int idx)
    {
        if(level>=triangle.size())
            return 0;
        if(dp[level][idx]!=-1)
            return dp[level][idx];
        int ans=triangle[level][idx];
        int left = INT_MAX, right = INT_MAX;
        // if(idx>=0)
            left=recur(triangle,level+1,idx);
        // if(idx)
            right=recur(triangle,level+1,idx+1);
        return dp[level][idx]=ans+min(left,right);
            
    }
    
    int minimumTotal(vector<vector<int>>& triangle)
    {
        for(int i=0;i<triangle.size();i++)
            dp.push_back(vector<int>(i+1, -1));
        // int ans=INT_MAX;
        return recur(triangle,0,0);
    }
};