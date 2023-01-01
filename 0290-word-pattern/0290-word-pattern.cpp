class Solution 
{
public:
    bool wordPattern(string pattern, string s) 
    {
        unordered_map<char,string> m;
        unordered_set<string> words;
        string word="";
        int curridx=0;
        for(int i=0;i<s.size();i++) 
        {
            if(s[i]!=' ') 
                word+=s[i];
            if(s[i]==' ' || i+1==s.size()) 
            {
                if(m.find(pattern[curridx])==m.end()) 
                {
                    if(words.find(word)==words.end()) 
                    {
                        m[pattern[curridx]]=word;
                        words.insert(word);
                    }
                    else                    
                        return false;
                }
                else if (m[pattern[curridx]].compare(word)!=0)       
                    return false;                
                word = "";
                curridx++;
            }
        }
        return curridx==pattern.size(); 
    }
};