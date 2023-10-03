class Solution {
public:
    int numIdenticalPairs(vector<int>& nums)
    {
        unordered_map<int,int> mp;
        for(int i:nums)
            mp[i]++;
        int ans=0;
        for(auto [i,j]:mp)
            ans+=(j*(j-1))/2;
        return ans;
    }
};