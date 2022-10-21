class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        unordered_map<int,vector<int>> m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]].push_back(i);
        for(auto i:m)
        {
            //cout<<i.first<<".  ";
            vector<int> v=i.second;
            //cout<<v[0]<<" ";
            for(int j=1;j<v.size();j++)
            {
                if(v[j]-v[j-1]<=k)
                    return true;
                //cout<<v[j]<<" ";
                
            }
        }
        return false;
        
    }
};