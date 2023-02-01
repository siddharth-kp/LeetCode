class Solution {
public:
    string gcdOfStrings(string str1, string str2)
    {
        string ans="";
        if(str1+str2!=str2+str1)
            return "";
        for(int i=0;i<str1.size() && i<str2.size();i++)
            if(str1[i]==str2[i])
                ans+=str1[i];
            else
                break;
        return ans.substr(0,gcd(str1.size(),str2.size()));
    }
};