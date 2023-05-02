// Tabulation

// class Solution {
// public:
//     int jump(vector<int>& nums)
//     {
//         vector<int> dp(nums.size(),INT_MAX-1);
//         dp[nums.size()-1]=0;
//         for(int i=nums.size()-2;i>=0;i--)
//         {
//             int jmp=nums[i];
//             for(int j=i+1;j<=i+jmp && j<nums.size();j++)
//                 dp[i]=min(dp[i],1+dp[j]);
//         }
//         return dp[0];
//     }
// };



// Memoization

class Solution {
public:
    
    int recur(int idx, vector<int> &nums, vector<int> &dp)
    {
        if(dp[idx]!=INT_MAX-1)
            return dp[idx];
        int jmp=nums[idx];
        for(int i=idx+1;i<=idx+jmp && i<nums.size();i++)
            dp[idx]=min(dp[idx],1+recur(i,nums,dp));
        return dp[idx];
    }
    
    int jump(vector<int>& nums)
    {
        vector<int> dp(nums.size(),INT_MAX-1);
        dp[nums.size()-1]=0;
        return recur(0,nums,dp);
    }
};