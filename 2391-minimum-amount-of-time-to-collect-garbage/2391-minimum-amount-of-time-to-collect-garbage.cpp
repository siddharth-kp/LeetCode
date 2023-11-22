class Solution {
private:
    int fun2(string str, char ch)
    {
        int cnt=0;
        for(char c:str)
            cnt += (ch==c);
        return cnt;
    }
    int fun(vector<string> &garbage, vector<int> travel, char c)
    {
        int last=-1;
        for(int i=0;i<garbage.size();i++)
        {
            for(char ch:garbage[i])
                if(ch==c)   last=i;
        }
        // cout<<c<<" "<<last<<endl;
        if(last==-1)
            return 0;
        int ans=0;
        ans+=fun2(garbage[0],c);
        for(int i=1;i<garbage.size();i++)
        {
            if(i-1==last)
                break;
            ans+=travel[i-1];
            ans+=fun2(garbage[i],c);
        }
        // cout<<c<<" "<<ans<<endl;
        return ans;
    }
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel)
    {
        return fun(garbage,travel,'P') + fun(garbage,travel,'M') + fun(garbage,travel,'G');
    }
};