class Solution {
public:
    int singleNonDuplicate(vector<int>& nums)
    {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<r)
        {
            int mid = l+(r-l)/2;
            if (mid%2)
            {
                if (mid-1>=0 && nums[mid]==nums[mid-1])
                    l=mid+1;
                else if(mid+1<n && nums[mid]==nums[mid+1])
                    r=mid;
                else
                    return nums[mid];
            }
            else
            {
                if (mid-1>=0 && nums[mid]==nums[mid-1])
                    r=mid;
                else if (mid+1<n && nums[mid]==nums[mid+1])
                    l=mid+1;
                else
                    return nums[mid];
            }
        }
        return nums[l+(r-l)/2];
    }
};