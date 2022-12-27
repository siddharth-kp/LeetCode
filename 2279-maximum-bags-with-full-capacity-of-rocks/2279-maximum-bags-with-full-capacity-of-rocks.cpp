class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks)
    {
        map<int,int> m;
        for(int i=0;i<rocks.size();i++)
            //if(capacity[i]>rocks[i])
                m[capacity[i]-rocks[i]]++;
        int ans=0;
        for(auto [i,j]:m)
        {
            if(additionalRocks-i*j>0)
            {
                additionalRocks-=i*j;
                ans+=j;
            }
            else
            {
                int u=0;
                for(u=0;u<j && additionalRocks>0;u++)
                {
                    ans++;
                    additionalRocks-=i;
                }
                if(additionalRocks<0)
                    ans--;
                break;
            }
        }
        return ans;
    }
};