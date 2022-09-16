// class Solution {
// public:
    
//     int solve(int index, int start, int end, vector<int>& nums, vector<int>& mul, vector<vector<int>> &dp)
//     {
//         if(index==nums.size())
//             return 0;
//         if(dp[index][start]!=INT_MIN)
//             return dp[index][start];
//         int ans =max( mul[index]*nums[start]+solve(index+1,start+1,end,nums,mul,dp),
//                                      mul[index]*nums[end]+solve(index+1,start,end-1,nums,mul,dp));
//         return dp[index][start]=ans;
        
//     }
    
//     int maximumScore(vector<int>& nums, vector<int>& mul)
//     {
//         int n= nums.size();
//         vector<vector<int>> dp(n,vector<int>(n,INT_MIN));
//         return solve(0,0,n-1,nums,mul,dp);
//     }
// };


class Solution {
public:
    int rec(int idx,int st,int end,vector<int>& nums,vector<int>& multi,vector<vector<int>> &dp){
        if(idx==multi.size()) return 0;
        if(dp[idx][st]!=INT_MIN) return dp[idx][st];
        int ans=INT_MIN;
        ans= max(multi[idx]*nums[st]+ rec(idx+1,st+1,end,nums,multi,dp),
                multi[idx]*nums[end]+ rec(idx+1,st,end-1,nums,multi,dp));
        return dp[idx][st]= ans;
    }
    int maximumScore(vector<int>& nums, vector<int>& multi) {
        vector<vector<int>> dp(multi.size(),vector<int>(multi.size(),INT_MIN));
        return rec(0,0,nums.size()-1,nums,multi,dp);
    }
};