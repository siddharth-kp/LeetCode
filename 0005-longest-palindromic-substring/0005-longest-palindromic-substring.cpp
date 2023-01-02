class Solution {
public:
    string longestPalindrome(string s)
    {
        int n=s.length();
        int maxlen=0,currlen=1;
        string ans=s.substr(0,1);
        for(int i=1;i<n-1;i++)
        {
            currlen=1;
            int left=i-1,right=i+1;
            while(s[left]==s[right])
            {
                currlen+=2;
                left--;
                right++;
                if(left<0 || right>n-1)
                    break;
            }
            left++;
            right--;
            if(currlen>maxlen)
            {
                maxlen=currlen;
                ans=s.substr(left,right-left+1);
            }
        }
        // cout<<maxlen<<endl;
        for(int i=0;i<n-1;i++)
        {
            // cout<<i<<endl;
            currlen=0;
            int left=i,right=i+1;
            while(s[left]==s[right])
            {
                // cout<<left<<" "<<right<<endl;
                currlen+=2;
                left--;
                right++;
                if(left<0 || right>n-1)
                    break;
            }
            left++;
            right--;
            if(currlen>maxlen)
            {
                maxlen=currlen;
                ans=s.substr(left,right-left+1);
            }
        }
        return ans;
    }
};