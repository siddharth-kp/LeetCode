class Solution {
private:
    void check(char c, int &count)
    {
        if(c=='a' || c=='e' || c=='o' || c=='i' || c=='u')
            count++;
        if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
            count++;
    }
    
public:
    bool halvesAreAlike(string s)
    {
        int count1=0,count2=0;
        for(int i=0;i<s.length();i++)
        {
            if(i<s.length()/2)
                check(s[i],count1);
            else
                check(s[i],count2);
        }
        //cout<<count;
        return count2==count1;
    }
};
