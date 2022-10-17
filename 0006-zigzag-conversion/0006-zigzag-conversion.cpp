class Solution {
public:
    string convert(string s, int numRows)
    {
        if(numRows==1)  return s;
        vector<string> ans(numRows);
        bool up = true;
        int ins = 0;
        for(int i=0;i<s.size();i++)
        {
            ans[ins].push_back(s[i]);
            if(ins==numRows-1)  up=false;
            else if(ins==0)  up=true;
            if(up)  ins++;
            else    ins--;
        }
        string str="";
        for(auto i:ans)
            for(auto j:i)
                str+=j;
        return str;
    }
};