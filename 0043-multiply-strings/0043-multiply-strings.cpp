class Solution {
private:
    string mul(string str, char c)
    {
        int n=c-'0';
        int carry=0;
        string ans="";
        for(int i=str.length()-1;i>=0;i--)
        {
            int temp=(str[i]-'0')*n;
            temp+=carry;
            ans=to_string(temp%10)+ans;
            carry=temp/10;
        }
        if(carry)
            ans=to_string(carry)+ans;
        return ans;
    }
    
    string addn(string str1, string str2)
    {
        string str="";
        reverse(str1.begin(),str1.end());
        reverse(str2.begin(),str2.end());
        if(str1.length()>str2.length())
            swap(str1,str2);
        int n1=str1.length(), n2=str2.length();
        int carry=0;
        for(int i=0;i<n1;i++)
        {
            int sum=((str1[i]-'0')+(str2[i]-'0')+carry);
            str.push_back((sum%10)+'0');
            carry=sum/10;
        }
        for(int i=n1;i<n2;i++)
        {
            int sum=((str2[i]-'0')+carry);
            str.push_back(sum%10+'0');
            carry=sum/10;
        }
        if(carry)
            str.push_back(carry+'0');
        reverse(str.begin(),str.end());
        return str;
    }
    
    // void removeleadingzeros(string &ans)
    // {
    //     string ans2="";
    //     bool start=false;
    //     for(int i=0;i<ans.size()-1;i++)
    //     {
    //         if(ans[i]!='0')
    //             start=true;
    //         if(start)
    //             ans2+=ans[i];
    //     }
    //     ans=ans2;
    // }
    
public:
    string multiply(string num1, string num2)
    {
        string ans="0";
        if(num1=="0" || num2=="0")
            return ans;
        for(int i=num2.length()-1;i>=0;i--)
        {
            string ans1=mul(num1,num2[i]);
            int zeros=num2.length()-1-i;
            while(zeros--)
                ans1+="0";
            ans=addn(ans,ans1);
        }
        // removeleadingzeros(ans);
        return ans;
    }
};