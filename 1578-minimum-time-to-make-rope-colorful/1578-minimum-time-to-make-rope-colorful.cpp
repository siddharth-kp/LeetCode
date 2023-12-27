class Solution {
public:
    int minCost(string colors, vector<int>& neededTime)
    {
        int maxi=neededTime[0], ans=0, cnt=1, clustersum=neededTime[0];
        for(int i=1;i<colors.size();i++)
        {
            if(colors[i]==colors[i-1])
            {
                maxi=max(maxi,neededTime[i]);
                clustersum += neededTime[i];
                cnt++;
            }
            else
            {
                if(cnt>1)
                    ans += clustersum-maxi;
                cnt=1;
                maxi=neededTime[i];
                clustersum=neededTime[i];
            }
            // cout<<"i:"<<i<<" maxi:"<<mini<<" cnt:"<<cnt<<" ans:"<<ans<<endl;
        }
        if(cnt>1)
            ans += clustersum-maxi;
        return ans;
    }
};