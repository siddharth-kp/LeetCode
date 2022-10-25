class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2)
    {
        string one="",two="";
        for(string word:word1)  for(char c:word)    one+=c;
        for(string word:word2)  for(char c:word)    two+=c;
        return one==two;
    }
};