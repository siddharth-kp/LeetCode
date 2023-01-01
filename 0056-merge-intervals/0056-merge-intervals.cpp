class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        vector<vector<int>>ans;
        vector<int>res;
        vector<int>arr1;
        vector<int>arr2;
        for(int i =0;i<intervals.size();i++)
        {
            arr1.push_back(intervals[i][0]);
            arr2.push_back(intervals[i][1]);
        }
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        res.push_back(arr1[0]);
        for(int i=0;i<intervals.size()-1;i++)
        {
            if(arr2[i]<arr1[i+1])
            {
                res.push_back(arr2[i]);
                ans.push_back(res);
                res.clear();
                res.push_back(arr1[i+1]);
            }
        }
        res.push_back(arr2[arr2.size()-1]);
        ans.push_back(res);
        return ans;
    }
};