class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries)
    {
        long long totalsum=0;
        int rows=n, cols=n;
        unordered_set<int> r,c;
        for(int i=queries.size()-1;i>=0;i--)
        {
            vector<int> v=queries[i];
            if(v[0]==0)
            {
                if(r.count(v[1]))
                    continue;
                r.insert(v[1]);
                totalsum+=cols*v[2];
                rows--;
            }
            else
            {
                if(c.count(v[1]))
                    continue;
                c.insert(v[1]);
                totalsum+=rows*v[2];
                cols--;
            }
        }
        return totalsum;
    }
};