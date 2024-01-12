class Solution {
public:
    bool halvesAreAlike(string s)
    {
        int val=0;
        auto check = [](char b)->bool{
            bool c=0;
            c |= b=='A' || b=='E' || b=='I' || b=='O' || b=='U';
            c |= b=='a' || b=='e' || b=='i' || b=='o' || b=='u';
            return c;
        };
        for(int i=0;i<s.length()/2;i++)
            val+=check(s[i]);
        for(int i=s.length()/2;i<s.length();i++)
            val-=check(s[i]);
        return val==0;
    }
};