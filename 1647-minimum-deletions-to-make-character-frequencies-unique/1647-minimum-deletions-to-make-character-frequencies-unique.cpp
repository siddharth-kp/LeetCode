class Solution {
public:
    int minDeletions(string s)
    {
        unordered_map<int,int> m;
        for(char ch:s)
            m[ch-'a']++;
        vector<int> f;
        for(auto [i,j]:m)
            f.push_back(j);
        sort(f.begin(),f.end());
        reverse(f.begin(),f.end());
        // m.clear();
        int curr=f[0];
        int ans=0;
        int cons=0;
        vector<int> f2(f.size());
        f2[0]=f[0];
        for(int i=1;i<f.size();i++)
        {
            if(f[i]==curr || f[i]>=f2[i-1])
                f2[i]=f2[i-1]-1;
            else
                f2[i]=f[i];
            curr=f[i];
        }
        for(int i=0;i<f.size();i++)
            ans+=(f2[i]>=0)?(f[i]-f2[i]):f[i];
        return ans;
    }
};