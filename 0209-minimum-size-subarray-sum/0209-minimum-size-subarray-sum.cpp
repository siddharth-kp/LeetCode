class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int low=0, high=0;
        long long sum=nums[low];
        bool found=false;
        int ans=INT_MAX;
        while(low<=high)
        {
            if(sum<target)
            {
                high++;
                if(high==nums.size())
                    break;
                sum+=nums[high];
            }
            else
            {
                found=true;
                ans=min(ans,high-low+1);
                sum-=nums[low];
                low++;
            }
        }
        if(found)
            return ans;
        return 0;
    }
};