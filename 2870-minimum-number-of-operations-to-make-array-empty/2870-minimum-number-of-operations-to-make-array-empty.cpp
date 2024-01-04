class Solution {
private:
    int op(int num)
    {
        return (num+2)/3;
    }
    
public:
    int minOperations(vector<int>& nums)
    {
        unordered_map<int,int> mp;
        for(int i:nums)
            mp[i]++;
        int ans=0;
        for(auto [i,j]:mp)
        {
            if(j==1)
                return -1;
            else
                ans+=op(j);
        }
        return ans;
    }
};