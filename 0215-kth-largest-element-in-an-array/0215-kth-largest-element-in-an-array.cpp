class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        map<int,int> mp;
        for(int i:nums)
            mp[i]++;
        for(int i=nums.size()-k;i>0;i--)
        {
            auto it=mp.begin();
            int a=it->first;
            mp[a]--;
            if(mp[a]==0)
                mp.erase(a);
        }
        return (mp.begin())->first;
    }
};