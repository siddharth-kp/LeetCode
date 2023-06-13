class SummaryRanges {
public:
    
    map<int,int> m;
    
    SummaryRanges() {}
    
    void addNum(int value)
    {
        m[value]=1;
    }
    
    vector<vector<int>> getIntervals()
    {
        vector<vector<int>> ans;
        for(auto &[i,j]:m)
        {
            if(ans.size() && (ans.back())[1]+1==i)
                (ans.back())[1]=i;
            else
                ans.push_back({i,i});
        }
        return ans;
    }
};
