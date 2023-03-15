class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int n=nums.size();
        for(int &i:nums)
            if(i<1 || i>n)
                i=n+1;
        for(int i:nums)
            if(abs(i)!=n+1 && nums[abs(i)-1]>=0)
                nums[abs(i)-1]*=-1;
        for(int i=0;i<n;i++)
            if(nums[i]>0)
                return i+1;
        return n+1;
    }
};