class Solution {
public:
    
    int fun(string str)
    {
        map<char,int> m;
        for(char ch:str)
            m[ch]++;
        return m.begin()->second;
    }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words)
    {
        vector<int> m(2001,0);
        for(string str:words)
            m[fun(str)]++;
        vector<int> prefix(2001,0);
        prefix[2000]=m[2000];
        for(int i=1999;i>=0;i--)
            prefix[i]=prefix[i+1]+m[i];
        for(int i=0;i<10;i++)
            cout<<m[i]<<" ";
        cout<<endl;
        for(int i=0;i<10;i++)
            cout<<prefix[i]<<" ";
        cout<<endl;
        vector<int> ans;
        for(string str:queries)
            ans.push_back(prefix[fun(str)+1]);
        return ans;
    }
};