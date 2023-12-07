class Solution {
public:
    string largestOddNumber(string num)
    {
        int ans=-1;
        for(int i=0;i<num.size();i++)
        {
            char c = num[i];
            if((c-'0')%2!=0)
                ans=i;
        }
        if(ans==-1)
            return "";
        return num.substr(0,ans+1);
    }
};