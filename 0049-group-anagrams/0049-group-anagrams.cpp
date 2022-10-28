class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        map<string,vector<string>> m;
        for(auto i:strs)
        {
            string s = i;
            sort(s.begin(),s.end());
            m[s].push_back(i);
        }
        vector<vector<string>> v;
        for(auto i:m)
            v.push_back(i.second);
        return v;
    }
};