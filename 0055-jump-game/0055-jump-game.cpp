class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        if(nums.size()==1)    return 1;
        vector<bool> dp(nums.size(),0);
        for(int i=nums.size()-2;i>=0;i--)
        {
            int jmp=nums[i];
            for(int j=i+1;j<=i+jmp && j<nums.size();j++)
                if(j==nums.size()-1 || dp[j])
                {
                    dp[i]=1;
                    break;
                }
        }
        return dp[0];
    }
};



// class Solution {
// public:
    
//     bool rec(int curr, int end, vector<bool> &dp, vector<int> &nums)
//     {
//         // cout<<curr<<endl;
//         if(curr>=end)
//             return true;
//         int jmp=nums[curr];
//         for(int i=curr+1;i<=curr+jmp && i<nums.size();i++)
//             if(rec(i,end,dp,nums)==1)
//             {
//                 dp[curr]=1;
//                 dp[i]=1;
//                 break;
//             }
//         return dp[curr];
//     }
    
//     bool canJump(vector<int>& nums)
//     {
//         vector<bool> dp(nums.size(),0);
//         int a= rec(0,nums.size()-1,dp,nums);
//         // for(int i:dp)
//         //     cout<<i<<" ";
//         return a;
//     }
// };