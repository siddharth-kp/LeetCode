class Solution {
public:
    
    int rob(vector<int>& nums)
    {
        if(nums.size()<=2)
            return *max_element(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> v(n), maxi(n,-1);
        v[n-1]=nums[n-1];
        v[n-2]=nums[n-2];
        for(int i=n-3;i>=0;i--)
        {
            v[i]=nums[i]+(*max_element(v.begin()+i+2,v.end()));
            //cout<<i<<" "<<v[i]<<endl;
        }
        return max(v[0],v[1]);
    }
};