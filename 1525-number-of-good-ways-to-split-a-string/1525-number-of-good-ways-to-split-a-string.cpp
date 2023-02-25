class Solution {
public:
    int numSplits(string s)
    {
        int ans=0;
        unordered_map<char,int> m1,m2;
        for(char c:s)
            m2[c]++;
        for(char c:s)
        {
            m1[c]++;
            m2[c]--;
            if(m2[c]==0)
                m2.erase(c);
            if(m1.size()==m2.size())
                ans++;
        }
        return ans;
    }
};