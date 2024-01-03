class Solution {
public:
    int numberOfBeams(vector<string>& bank)
    {
        vector<int> cnt;
        for(string str:bank)
        {
            int temp=0;
            for(char c:str)
                temp += c=='1';
            if(temp>0)
                cnt.push_back(temp);
        }
        int ans=0;
        for(int i=1;i<cnt.size();i++)
            ans += cnt[i]*cnt[i-1];
        return ans;
    }
};