class Solution {
public:
    int maxPoints(vector<vector<int>>& points)
    {
        int maxi=-1;
        for(int i=0;i<points.size();i++)
        {
            int x1=points[i][0];
            int y1=points[i][1];
            int inf=0;
            unordered_map<double,int> m;
            for(int j=0;j<points.size();j++)
            {
                if(j==i)
                    continue;
                double x2=points[j][0];
                double y2=points[j][1];
                if(x2==x1)
                    inf++;
                else
                    m[(y2-y1)/(x2-x1)]++;
            }
            int tempmax=-1;
            for(auto [q,w]:m)
                tempmax=max(tempmax,w);
            tempmax=max(tempmax,inf);
            maxi=max(maxi,tempmax);
        }
        return maxi+1;
    }
};