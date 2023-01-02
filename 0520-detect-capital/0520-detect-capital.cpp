class Solution {
public:
    bool detectCapitalUse(string word) 
    {
        int A='A';
        int Z='Z';
        int a='a';
        int z='z';
        if(word.length()==1)
            return true;
        //if(!(word[0]>=A && word[0]<=Z))
        //    return false;
        int b=0;
        if(word[1]>=A && word[1]<=Z)
            b=1;
        if(  (!(word[0]>=A && word[0]<=Z)) && b==1)
            return false;
        
        if(b==0)
        {
            for(int i=2;i<word.length();i++)
            {
                if(!(word[i]>=a && word[i]<=z))
                    return false;
            }
        }
        else
        {
            for(int i=2;i<word.length();i++)
            {
                if(!(word[i]>=A && word[i]<=Z))
                    return false;
            }
        }
        return true;
    }
};