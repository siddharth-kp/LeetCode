class Solution {
public:
    vector<int> dp;

    int recur(vector<int> &nums, int target)
    {
        if(target<0)
            return 0;
        if(target==0)
            return 1;
        if(dp[target]!=-1)
            return dp[target];
        int ans=0;
        for(int i:nums)
            ans+=recur(nums,target-i);
        return dp[target]=ans;
    }

    int combinationSum4(vector<int>& nums, int target)
    {
        dp.resize(target+1,-1);
        return recur(nums,target);        
    }
};