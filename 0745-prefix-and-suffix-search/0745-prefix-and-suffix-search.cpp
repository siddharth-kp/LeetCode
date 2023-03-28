class WordFilter {
public:
    
    unordered_map<string,int> m;
    
    WordFilter(vector<string>& words)
    {
        for(int k=0;k<words.size();k++)
        {
            string str=words[k];
            for(int i=0;i<str.length();i++)
            {
                string pre=str.substr(0,i+1);
                for(int j=0;j<str.length();j++)
                {
                    string suf = str.substr(j);
                    m[pre+"|"+suf]=k+1;
                }
            }
        }
    }
    
    int f(string pref, string suff)
    {
        return m[pref+"|"+suff]-1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */