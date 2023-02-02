class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order)
    {
        map<char,int> m;
        int cnt=0;
        for(auto it: order)
            m[it]=++cnt;
        bool flag=false;
        for(int i=0;i<words.size()-1;i++)
        {
            string word = words[i];
            string next = words[i+1];
            int len = min(word.size(),next.size());
            for(int i=0;i<len;i++)
            {
                if(m[word[i]]>m[next[i]])
                    return false;
                if(m[word[i]]<m[next[i]])
                {
                    flag=1;
                    break;
                }
            }
            if(!flag && next.size()<word.size())
                return false;
        }
        return true;
    }
};