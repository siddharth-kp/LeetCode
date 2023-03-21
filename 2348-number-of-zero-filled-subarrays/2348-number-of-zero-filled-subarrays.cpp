class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums)
    {
        int cnt=0;
        vector<long long> v;
        for(int i:nums)
        {
            if(i==0)
                cnt++;
            else
            {
                if(cnt!=0)
                    v.push_back(cnt);
                cnt=0;
            }
        }
        if(cnt!=0)
            v.push_back(cnt);
        long long ans=0;
        for(long long i:v)
            ans+=(i*(i+1))/2;
        return ans;
    }
};