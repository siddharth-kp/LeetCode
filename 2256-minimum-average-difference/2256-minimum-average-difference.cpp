class Solution {
public:
    
    int abs(int a)
    {
        if(a>0)
            return a;
        else
            return -1*a;
    }
    
    int minimumAverageDifference(vector<int>& nums) 
    {
        long long int totsum=0;
        for(int i:nums) totsum+=i;
        long long int currsum=0;
        vector<long long int> diff;
        for(int i=0;i<nums.size();i++)
        {
            currsum+=nums[i];
            totsum-=nums[i];
            if(i!=nums.size()-1)
                diff.push_back(abs(currsum/(i+1)-totsum/(nums.size()-i-1)));
        }
        diff.push_back(currsum/nums.size());
        int mini=0,minisum=INT_MAX;
        for(int i=0;i<diff.size();i++)
        {
            cout<<diff[i]<<" ";
            if(diff[i]<minisum)
            {
                minisum=diff[i];
                mini=i;
            }
        }
        return mini;
    }
};