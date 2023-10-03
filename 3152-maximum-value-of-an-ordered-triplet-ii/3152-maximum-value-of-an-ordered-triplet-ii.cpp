#define ll long long

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> left(n), right(n);
        left[0]=nums[0];
        for(int i=1;i<n;i++)
            left[i]=max(left[i-1],nums[i-1]);
        right[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
            right[i]=max(right[i+1],nums[i+1]);
        ll ans=0;
        for(int i=1;i<n-1;i++)
        {
            ll temp = ((ll)left[i] - (ll)nums[i]) * (ll)right[i];
            if(temp>ans)
                ans=temp;
        }
        return ans;
    }
};