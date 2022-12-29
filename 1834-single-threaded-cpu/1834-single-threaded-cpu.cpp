class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks)
    {
        vector<vector<int>> lst;
        for(int i = 0; i < tasks.size(); i++)
            lst.push_back({tasks[i][0], tasks[i][1], i});
        sort(lst.begin(), lst.end());
        vector<int> res;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        long long i = 0, t = 0;
        while(i < lst.size())
        {
            if(minHeap.empty() && t < lst[i][0])
                t = lst[i][0];   // when it is in idle
            while(i<lst.size() && lst[i][0] <= t) 
            {
                minHeap.push({lst[i][1], lst[i][2]});
                i++;
            }
            pair<int, int> curr = minHeap.top();
            minHeap.pop();
            t += curr.first;
            res.push_back(curr.second);
        }
        while(!minHeap.empty()) 
        {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return res;
    }
};