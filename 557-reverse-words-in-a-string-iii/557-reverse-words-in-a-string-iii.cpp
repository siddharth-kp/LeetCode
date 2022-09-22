class Solution {
public:
    string reverseWords(string s)
    {
        s+= " ";
        string str = "";
        string ans = "";
        //vector<string> words;
        for(char c:s)
        {
            if(c!=' ')
                str+=c;
            else
            {
                reverse(str.begin(),str.end());
                ans+=str;
                ans+=" ";
                str="";
            }
        }
        return ans.substr(0,s.length()-1);
    }
};