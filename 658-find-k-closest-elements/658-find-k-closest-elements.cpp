class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x)
    {
        vector<pair<int,int>> v;
        for(int i:arr)
            v.push_back({abs(i-x),i});
        sort(v.begin(),v.end());
        // for(auto i:v)
        //     cout<<i.first<<" "<<i.second<<endl;
        vector<int> ans;
        for(int i=0;i<k;i++)
            ans.push_back(v[i].second);
        sort(ans.begin(),ans.end());
        return ans;
    }
};