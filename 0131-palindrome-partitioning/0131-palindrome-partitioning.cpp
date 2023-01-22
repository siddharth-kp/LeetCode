class Solution {
public:
    
    bool check(string s)
    {
        int l=0,r=s.length()-1;
        while(l<r)
        {
            if(s[l]!=s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    
    void fill(string s, vector<string> &v, vector<vector<string>> &ans)
    {
        if(s.size()==0)
        {
            ans.push_back(v);
            return;
        }
        for(int i=0;i<s.length();i++)
        {
            string palind = s.substr(0,i+1);
            string rem = s.substr(i+1);
            if(check(palind))
            {
                v.push_back(palind);
                fill(rem,v,ans);
                v.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) 
    {
        vector<string> v;
        vector<vector<string>> ans;
        fill(s,v,ans);
        return ans;
    }
};