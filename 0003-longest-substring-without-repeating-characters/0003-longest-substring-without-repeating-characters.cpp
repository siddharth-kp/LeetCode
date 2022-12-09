class Solution {
public:
    int lengthOfLongestSubstring(string str)
    {
        if(str.size()==0)   return 0;
        int left=0,right=0;
        unordered_map<char,int> m;
        //m[str[0]]=0;
        int currlen=1,maxlen=1;
        while(right!=str.length())
        {
            //cout<<left<<" "<<right<<" "<<m.count(str[right])<<endl;
            if(left==right)
            {
                m.clear();
                m[str[left]]=left;
                right++;
            }
            else if(m.count(str[right]))
            {
                for(int i=left;i<=m[str[right]]-1;i++)
                    m.erase(str[i]);
                left=m[str[right]]+1;
                m[str[right]]=right;
                right++;;
            }
            else
            {
                currlen=right-left+1;
                maxlen=max(currlen,maxlen);
                m[str[right]]=right;
                right++;
            }
            //cout<<left<<" "<<right<<" "<<maxlen<<endl<<endl;
        }
        return maxlen;
    }
        
};

/*

"abba"
"abcabcbb"
"bbbbb"
"pwwkew"
"au"
"cdd"
"aab"

*/