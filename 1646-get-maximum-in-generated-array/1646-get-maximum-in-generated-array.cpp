class Solution {
public:
    
    vector<int> nums;
    
    int getMaximumGenerated(int n)
    {
        if(n<=1)
            return n;
        nums.resize(n+1);
        nums[0]=0;
        nums[1]=1;
        for(int i=2;i<=n;i++)
        {
            if(i%2)
                nums[i]=nums[i/2]+nums[i/2+1];
            else
                nums[i]=nums[i/2];
        }
        int maxi=-1;
        for(int i:nums)
            maxi=max(maxi,i);
        return maxi;
    }
};