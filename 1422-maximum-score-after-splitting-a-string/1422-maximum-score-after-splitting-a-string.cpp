class Solution {
public:
    int maxScore(string s)
    {
        vector<int> v(s.size(),0);
        for(int i=0;i<s.size();i++)
        {
            if(i==0)
                v[i]=(s[i]=='0');
            else
                v[i]=v[i-1]+(s[i]=='0');
        }
        int maxi=0;
        auto max = [](int a, int b) -> int {
            if(a>b)
                return a;
            else
                return b;
        };
        for(int i=0;i<s.size()-1;i++)
            maxi=max(maxi,v[i]+s.size()-i-1-v.back()+v[i]);
        return maxi;
    }
};