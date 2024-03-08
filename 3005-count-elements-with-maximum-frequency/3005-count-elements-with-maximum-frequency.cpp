class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> mp, mp2;
        for(int i:nums)
            mp[i]++;
        for(auto [i,j]:mp)
            mp2[j]++;
        return mp2.rbegin()->first*mp2.rbegin()->second;
    }
};