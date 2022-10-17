class Solution {
public:
    bool checkIfPangram(string sentence)
    {
        int start='a',end='z';
        vector<int> a(26,0);
        for(char ch:sentence)
        {
            if(!(ch>=start && ch<=end))
                return false;
            a[ch-'a']++;
        }
        // for(int i=0;i<26;i++)
        //     cout<<i+1<<" "<<a[i]<<endl;
        for(int i:a)
            if(i<1)
                return false;
        return true;
    }
};