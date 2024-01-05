class Solution {
private:
    vector<int> nums,dp;
    
    int recur(int idx)
    {
        if(idx>=nums.size())
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        int ans=0;
        for(int i=idx;i<nums.size();i++)
            if(nums[i]>nums[idx])
                ans=max(ans,1+recur(i));
        return dp[idx]=ans;
    }
public:
    int lengthOfLIS(vector<int>& nums)
    {
        this->nums=nums;
        dp.resize(nums.size(),-1);
        int ans=0;
        for(int i=0;i<nums.size();i++)
            ans=max(ans,recur(i));
        // for(int i:dp)
        //     cout<<i<<" ";
        // cout<<endl;
        return 1+ans;
    }
};