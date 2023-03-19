class Solution {
public:
    
    bool static cmp(string &a, string &b)
    {
        return a+b<b+a;
    }
    
    string largestNumber(vector<int>& nums)
    {
        vector<string> v;
        for(int i:nums)
            v.push_back(to_string(i));
        sort(v.begin(),v.end(),cmp);
        reverse(v.begin(),v.end());
        string ans="";
        for(auto i:v)
            ans+=i;
        if(ans[0]=='0')
        return "0";
        else 
            return ans;
    }
};