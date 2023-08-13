class Solution {
private:
    vector<int> nums;
    vector<int> dp;

    bool recur(int idx)
    {
        if(idx==nums.size())
            return 1;
        if(dp[idx]!=-1)
            return dp[idx];
        bool ans1=false, ans2=false, ans3=false;
        if(idx+1<=nums.size()-1)
        {
            ans1 = ans1 | (nums[idx]==nums[idx+1]);
            if(ans1)
                ans1 = ans1 & recur(idx+2);
        }
        if(idx+2<=nums.size()-1)
        {
            ans2 = ans2 | (nums[idx]==nums[idx+1] && nums[idx+1]==nums[idx+2]);
            if(ans2)
                ans2 = ans2 & recur(idx+3);
            ans3 = ans3 | (nums[idx+1]-nums[idx]==1 && nums[idx+2]-nums[idx+1]==1);
            if(ans3)
                ans3 = ans3 & recur(idx+3);
        }
        return dp[idx] = ans1 | ans2 | ans3;
    }
public:
    bool validPartition(vector<int>& nums)
    {
        this->nums=nums;
        dp.resize(nums.size()+1,-1);
        return recur(0);        
    }
};