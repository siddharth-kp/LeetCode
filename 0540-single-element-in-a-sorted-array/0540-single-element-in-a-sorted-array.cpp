class Solution {
public:
    int singleNonDuplicate(vector<int>& nums)
    {
        if(nums.size()==1)
            return nums[0];
        int n=nums.size();
        if(nums[0]!=nums[1])
            return nums[0];
        if(nums[n-1]!=nums[n-2])
            return nums[n-1];
        for(int i=1;i<n-1;i++)
        {
            int cnt=0;
            if(nums[i]!=nums[i-1])
                cnt++;
            if(nums[i+1]!=nums[i])
                cnt++;
            if(cnt==2)
                return nums[i];
        }
        return 0;
    }
};