class Solution {
public:
    static bool compare(pair<int, int> p1, pair<int, int> p2)
    {
        return p1.second > p2.second;
    }
    
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime)
    {
        int start = 0, result = 0;
        vector<pair<int,int>> ans;
        for(int i=0;i<plantTime.size();i++)
            ans.push_back({plantTime[i], growTime[i]});
        sort(ans.begin(),ans.end(),compare);
        for(int i=0; i<plantTime.size(); i++)
        {
            start += ans[i].first;
            result = max(result,start+ans[i].second);
        }
        return result;
    }
};