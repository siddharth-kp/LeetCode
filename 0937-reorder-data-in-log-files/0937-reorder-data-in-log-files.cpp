class Solution {
private:
    static bool cmp(string &a, string &b)
    {
        int sp1=-1, sp2=-1;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]==' ')
            {
                sp1=i+1;
                break;
            }
        }
        for(int i=0;i<b.size();i++)
        {
            if(b[i]==' ')
            {
                sp2=i+1;
                break;
            }
        }
        if(a.substr(sp1)!=b.substr(sp2))
            return a.substr(sp1)<b.substr(sp2);
        else
            return a<b;
    }
    
    bool letter(string &str)
    {
        int sp=-1;
        for(int i=0;i<str.size();i++)
            if(str[i]==' ')
            {
                sp=i+1;
                break;
            }
        return !(str[sp]>='0' && str[sp]<='9');
    }
    
public:
    vector<string> reorderLogFiles(vector<string>& logs)
    {
        vector<string> res;
        for(string str:logs)
            if(letter(str))
                res.push_back(str);
        sort(res.begin(), res.end(), cmp);
        for(string str:logs)
            if(!letter(str))
                res.push_back(str);
        return res;   
    }
};
/*
["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo","a2 act car"]
*/