class Solution {
public:
    string destCity(vector<vector<string>>& paths)
    {
        map<string,string> mp;
        for(auto v:paths)
            mp[v[0]]=v[1];
        string str = paths[0][0];
        while(mp.count(str))
            str=mp[str];
        return str;
    }
};