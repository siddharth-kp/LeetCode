class Solution {
public:
    
    bool check(string s, string t)
    {
        map<char,char> m;
        map<char,int> m2;
        int l = s.length();
        for(int i=0;i<l;i++)
        {
            if(m2[s[i]]++ && m[s[i]]!=t[i])
                    return false;
            else
                m[s[i]]=t[i];
        }
        return true;
    }
    
    bool isIsomorphic(string s, string t)
    {
        return check(s,t) & check(t,s);
    }
};