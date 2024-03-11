class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int> mp;
        for(char c:s)
            mp[c]++;
        string ans="";
        for(char c:order)
            while(mp[c]--)
                ans += c;
        for(auto [i,j]:mp)
            while(mp[i]>0 && mp[i]--)
                ans += i;
        return ans;
    }
};