class Solution {
public:
    int minimizeArrayValue(vector<int>& nums)
    {
        long long int prefix_sum=0;
        long long int ans=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            prefix_sum+=nums[i];
            ans=max(ans,(prefix_sum+i)/(i+1));
        }
        return ans;
    }
};