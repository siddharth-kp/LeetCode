//  Tabulation

// class Solution {
// public:
//     bool canJump(vector<int>& nums)
//     {
//         if(nums.size()==1)    return 1;
//         vector<bool> dp(nums.size(),0);
//         for(int i=nums.size()-2;i>=0;i--)
//         {
//             int jmp=nums[i];
//             for(int j=i+1;j<=i+jmp && j<nums.size();j++)
//                 if(j==nums.size()-1 || dp[j])
//                 {
//                     dp[i]=1;
//                     break;
//                 }
//         }
//         return dp[0];
//     }
// };


// Memoization


class Solution {
public:
    bool recur(int idx, vector<int>& nums, vector<int> &dp)
    {
        // cout<<idx<<endl;
        if(dp[idx]!=-1)
            return dp[idx];
        if(idx>nums.size()-1)
            return 1;
        int jmp=nums[idx];
        for(int i=idx+1;i<=idx+jmp && i<nums.size();i++)
            if(recur(i,nums,dp))
                return dp[idx]=1;
        return dp[idx]=0;
    }
    
    bool canJump(vector<int>& nums)
    {
        vector<int> dp(nums.size(),-1);
        dp[nums.size()-1]=1;
        return recur(0,nums,dp);
    }
};