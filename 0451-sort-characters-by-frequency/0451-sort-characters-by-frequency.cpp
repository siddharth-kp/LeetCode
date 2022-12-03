class Solution {
public:
    string frequencySort(string s)
    {
        map<char,int> m;
        for(char c:s)   m[c]++;
        map<int,vector<char>> m2;
        for(auto i:m)   m2[i.second].push_back(i.first);
        string str="";
        for(auto i:m2)
            for(char c:i.second)
                for(int j=0;j<i.first;j++)
                    str+=c;
        reverse(str.begin(),str.end());
        return str;
    }
};