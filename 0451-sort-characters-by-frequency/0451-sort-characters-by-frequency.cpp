class Solution {
public:
    
    static bool cmp(pair<char,int>& a,pair<char,int>& b)
    {
        return a.second>b.second;
    }
    
    string frequencySort(string s)
    {
        // map<char,int> m;
        // for(char c:s)   m[c]++;
        // map<int,vector<char>> m2;
        // for(auto i:m)   m2[i.second].push_back(i.first);
        // string str="";
        // for(auto i:m2)
        //     for(char c:i.second)
        //         for(int j=0;j<i.first;j++)
        //             str+=c;
        // reverse(str.begin(),str.end());
        // return str;
        
        
        // faster
        vector<pair<char,int>> v(256);
        for(auto it:s)
        {
            v[it].first=it;           
            v[it].second+=1;          
        }
        sort(v.begin(),v.end(),cmp);
        string ans;                   
        for(auto it:v) 
            for(int j=0;j<it.second;j++)
                ans+=it.first;
        return ans;
    }
};