class Solution {
public:
    bool closeStrings(string word1, string word2)
    {
        if(word1.length()!=word2.length())  return 0;
        vector<int> table1(26,0), table2(26,0);
        for(char c:word1)   table1[c-'a']++;
        for(char c:word2)   table2[c-'a']++;
        // for(int i=0;i<table1.size();)
        // {
        //     if(table1[i]==0)
        //         table1.erase(table1.begin()+i);
        //     else
        //         i++;
        // }
        // for(int i=0;i<table2.size();)
        // {
        //     if(table2[i]==0)
        //         table2.erase(table2.begin()+i);
        //     else
        //         i++;
        // }

        for(int i=0;i<26;i++)
            if((table1[i]==0 && table2[i]!=0) || (table1[i]!=0 && table2[i]==0))
                return 0;
        sort(table1.begin(),table1.end());
        sort(table2.begin(),table2.end());
        return table1==table2;
    }
};