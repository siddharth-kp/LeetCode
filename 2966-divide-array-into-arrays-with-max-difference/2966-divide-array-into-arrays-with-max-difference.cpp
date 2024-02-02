class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k)
    {        
        sort(nums.begin(), nums.end());
        bool ans=true;
        for(int i=2;i<nums.size();i+=3)
            ans &= nums[i]<=nums[i-2]+k;
        if(!ans)
            return {};
        vector<vector<int>> res;
        for(int i=2;i<nums.size();i+=3)
        {
            vector<int> temp;
            temp.push_back(nums[i-2]);
            temp.push_back(nums[i-1]);
            temp.push_back(nums[i]);
            res.push_back(temp);
        }
        return res;
    }
};