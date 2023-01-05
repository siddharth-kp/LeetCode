class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points)
    {
        sort(points.begin(),points.end());
        int ans=1;
        int lastpoint=points[0][1];
        for(auto i:points)
        {
            if(i[0]>lastpoint)
            {
                ans++;
                lastpoint=i[1];
            }
            lastpoint=min(i[1],lastpoint);
        }
        return ans;
    }
};