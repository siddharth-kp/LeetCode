bool sort2(const pair<int,int> &a, const pair<int,int> &b)
{
    return (a.second < b.second);
}
    
class Solution 
{
    public:    
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        if(points.size()==0)
            return 0;
        if(points.size()==1)
            return 1;
        vector< pair<int,int> > v;
        for(int i=0;i<points.size();i++)
            v.push_back({points[i][0],points[i][1]});
        sort(v.begin(),v.end(),sort2);
        long long int a=1, prev = v[0].second;
        for(int i=1;i<v.size();i++)
        {
            if(v[i].first>prev)
            {
                a++;
                prev=v[i].second;
            }
               
        }
        return a;
        
    }
};