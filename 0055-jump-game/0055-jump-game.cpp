class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int n = nums.size();
        vector<bool> v(n,0);
        v[n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
            int num=nums[i];
            for(int j=1;j<=num && i+j<n;j++)
                if(v[i+j]==1)
                {
                    v[i]=1;
                    break;
                }
        }
        // for(int i:v)
        //     cout<<i<<" ";
        // cout<<endl;
        return v[0];
    }
};