class Solution {
public:
    int lengthOfLongestSubstring(string str)
    {
        if(str.size()==0)   return 0;
        int left=0,right=0;
        unordered_set<char> s;
        int currlen=1,maxlen=1;
        while(right!=str.length())
        {
            if(left==right)
            {
                s.clear();
                s.insert(str[left]);
                right++;
            }
            else if(s.count(str[right]))
            {
                s.erase(str[left]);
                left++;
            }
            else
            {
                s.insert(str[right]);
                currlen=right-left+1;
                maxlen=max(currlen,maxlen);
                right++;
            }
        }
        return maxlen;
    }
        
};