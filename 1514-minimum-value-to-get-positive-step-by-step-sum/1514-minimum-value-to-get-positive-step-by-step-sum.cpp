class Solution {
public:
    int minStartValue(vector<int>& nums)
    {
        int total=0, mini=INT_MAX;
        for(int i:nums)
        {
            total+=i;
            mini=min(mini,total);
        }
        int ans = 1 - mini;
        if(ans<=0)
            ans=1;
        return ans;
        // start(ans) + mini = 1
    }
};