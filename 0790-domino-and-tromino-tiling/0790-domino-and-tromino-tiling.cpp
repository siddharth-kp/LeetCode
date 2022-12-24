class Solution {
public:
    int mod=1000000007;
    int numTilings(int n)
    {
        if(n==1 || n==2)
            return n;
        vector<long long>v(3,0);
        v[0]=1;
        v[1]=2;
        v[2]=5;
        int ans=0;
        for(int i=3;i<n;i++)
        {
            ans=(2*v[2]+v[0])%mod;
            v[0]=v[1];
            v[1]=v[2];
            v[2]=ans;
        }
        return v[2];
    }
};