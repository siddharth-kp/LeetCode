class Solution {
public:
    int minOperations(string s)
    {
        int cnt1=0, cnt2=0, ok=1;
        for(int i=0;i<s.size();i++)
        {
            cnt1 += (s[i]-'0' != ok);
            cnt2 += (s[i]-'0' == ok);
            ok=1-ok;
        }
        return min(cnt1,cnt2);
    }
};