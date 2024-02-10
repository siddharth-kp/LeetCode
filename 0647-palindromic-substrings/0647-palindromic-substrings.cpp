class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for(int mid=0;mid<s.size();mid++)
        {
            int l=mid, r=mid;
            // cout<<mid<<" ->\n";
            while(l>=0 && r<s.size())
            {
                // cout<<l<<" "<<r<<endl;
                if(s[l]==s[r])
                {
                    ans++;
                    l--;
                    r++;
                }
                else
                    break;
            }
        }
        for(int midl=0;midl<s.size()-1;midl++)
        {
            int l =midl, r=midl+1;
            // cout<<midl<<" "<<midl+1<<" ->\n";
            while(l>=0 && r<s.size())
            {
                if(s[l]==s[r])
                {
                    // cout<<l<<" "<<r<<endl;
                    ans++;
                    l--;
                    r++;
                }
                else
                    break;
            }
        }
        return ans;
    }
};