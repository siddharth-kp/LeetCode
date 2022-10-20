class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        unordered_map<string, int> m;
        for(auto s: words)  m[s]++;
        map<int, vector<string>, greater<int>> m2;
        for(auto i:m)  m2[i.second].push_back(i.first);
        int count=0;
        vector<string> res;
        auto it = m2.begin();
        while(count<k)
        {
            sort(it->second.begin(), it->second.end());
            for(auto i:it->second)
            {
                res.push_back(i);
                count++;
                if(count == k)  return res;
            }
            it++;
        }
        return res;
    }
};