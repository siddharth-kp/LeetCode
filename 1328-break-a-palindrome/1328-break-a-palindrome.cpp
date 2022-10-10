class Solution {
public:
    string breakPalindrome(string palindrome)
    {
        // if(palindrome.length()<=1)  return "";
        // int mini = -1, mini_char='9';
        // map<char,vector<int>> m;
        // for(int i=0;i<palindrome.size();i++)  m[palindrome[i]].push_back(i);
        // if(m.size()==1)
        // {
        //     if(palindrome[0]=='a')
        //         return palindrome.substr(0,1)+'b'+palindrome.substr(2,palindrome.length()-2);
        //     else
        //         return 'a'+palindrome.substr(1,palindrome.length()-1);
        // }
        // if(palindrome[0]!='a')
        //     return 'a'+ palindrome.substr(1,palindrome.length()-1);
        // if(m.size()==2 && palindrome[0]=='a')
        // {
        //     if(((*(++m.begin())).second).size()==1)
        //         return palindrome.substr(0,palindrome.size()-1)+'b';
        //     else
        //     {
        //         int pos2 = ((*(++m.begin())).second)[0]; // first b
        //         return palindrome.substr(0,pos2)+'a'+palindrome.substr(pos2+1,palindrome.length()-pos2);
        //     }
        // }
        // int pos1 = ((*m.begin()).second)[1]; // second a
        // int pos2 = ((*(++m.begin())).second)[0]; // first b
        // cout<<pos1<<" "<<pos2;
        // if(pos1<pos2)
        //     return palindrome.substr(0,pos1)+'b'+palindrome.substr(pos1+1,palindrome.length()-pos1);
        // else
        //     return palindrome.substr(0,pos2)+'a'+palindrome.substr(pos2+1,palindrome.length()-pos2);
        int n=palindrome.length();
        if(n==1)return "";
        int count =0;
        for(int i=0;i<n;i++)
        {
            if(palindrome[i]!='a')
            {  count++;
            
            }
        }
        if(count>1)
        {
            
        int i=0;
        for( i=0;i<n;i++)
        {
          if(palindrome[i]!='a')
          {
              palindrome[i]='a';break;
          }
          
        }
        if(i==n)
            palindrome[1]='b';
        }
       
        else
        {
            palindrome[n-1]='b';
        }
        return palindrome;
    }
};