// Tabulation

class Solution {
public:
    int jump(vector<int>& nums)
    {
        vector<int> dp(nums.size(),INT_MAX-1);
        dp[nums.size()-1]=0;
        for(int i=nums.size()-2;i>=0;i--)
        {
            int jmp=nums[i];
            for(int j=i+1;j<=i+jmp && j<nums.size();j++)
                dp[i]=min(dp[i],1+dp[j]);
        }
        return dp[0];
    }
};