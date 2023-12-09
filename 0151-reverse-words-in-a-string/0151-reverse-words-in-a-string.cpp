class Solution {
private:
    string trim(string str)
    {
        int idx1, idx2;
        for(int i=0;i<str.size();i++)
            if(str[i]!=' ')
            {
                idx1=i;
                break;
            }
        for(int i=str.size()-1;i>=0;i--)
            if(str[i]!=' ')
            {
                idx2=i;
                break;
            }
        str = str.substr(idx1,idx2-idx1+1);
        string str2="";
        for(int i=0;i<str.size();i++)
        {
            if(i==0)
                str2.push_back(str[i]);
            else if(str[i]==' ' && str[i-1]==' ')
                continue;
            else
                str2.push_back(str[i]);
        }
        return str2;
    }
public:
    string reverseWords(string s)
    {
        s = trim(s);
        string str="", temp=" ";
        for(char c:s)
        {
            if(c!=' ')
                temp+=c;
            else
            {
                str=temp+str;
                temp=" ";
            }
        }
        str=temp+str;
        return str.substr(1);
    }
};