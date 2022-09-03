class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums)
    {
        // check if all negative else total sum - min_subarray_sum
        // bool pos=0;
        // int maxi=INT_MIN;
        // for(const int i:nums)
        //     if(i<0)
        //         maxi=max(maxi,i);
        //     else if(i>0)
        //         pos=1;
        // if(!pos)    return maxi;
        // int total=0,mini=0;
        // for(const int i:nums)
        // {
        //     total+=i;
        //     mini+=i;
        //     if(mini>0)  mini=0;
        // }
        // return total-mini;
        
        bool pos=0;
        int maxim=INT_MIN;
        for(int i:nums)
        {
            if(i>0)
            {
                pos=1;
                break;
            }
            maxim=max(maxim,i);
        }
        if(!pos)    return maxim;
        
        int total=0,mini=0,maxi=0,totmini=INT_MAX,totmaxi=INT_MIN;
        for(int i:nums)
        {
            total+=i;
            mini+=i;
            if(mini>0)  mini=0;
            totmini=min(mini,totmini);
            maxi+=i;
            if(maxi<0)  maxi=0;
            totmaxi=max(totmaxi,maxi);
        }
        return max(totmaxi,total-totmini);
    }
};