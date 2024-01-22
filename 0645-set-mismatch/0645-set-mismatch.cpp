class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums)
    {
        int maxi = *max_element(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        for(int i=1;i<=maxi;i++)    mp[i]*=1;
        for(int i:nums) mp[i]++;
        int f=-1, s=-1;
        for(auto [i,j]:mp)
        {
            if(j==2)    f=i;
            if(j==0)    s=i;
        }
        if(s==-1)
            return {f,maxi+1};
        else
            return {f,s};
    }
};