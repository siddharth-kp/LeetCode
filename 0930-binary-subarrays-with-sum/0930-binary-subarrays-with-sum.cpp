class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal)
    {
        int cumsum=0, ans=0;
        unordered_map<int,int> mp;
        for(int i:nums)
        {
            cumsum += i;
            ans += mp[cumsum-goal];
            ans += (cumsum==goal);
            mp[cumsum]++;
        }
        return ans;
    }
};