class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int64_t prod=1;
        int zero_cnt=0;
        bool flag=1;
        for(int i:nums)
        {
            if(i==0)
            {
                zero_cnt++;
                continue;
            }
            prod*=i;
            flag=0;
        }
        vector<int> ans;
        if(flag)
        {
            ans.resize(nums.size(),0);
            return ans;
        }
        for(int i:nums)
            if(zero_cnt>0 && i!=0)
                ans.push_back(0);
            else if(i!=0)
                ans.push_back(prod/i);
            else if(zero_cnt>1)
                ans.push_back(0);
            else
                ans.push_back(prod);
        return ans;
    }
};