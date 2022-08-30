class Solution {
public:
    vector<int> runningSum(vector<int>& nums)
    {
        vector<int> rs;
        int sum=0;
        for(const int i:nums)
        {
            sum+=i;
            rs.push_back(sum);
        }
        return rs;
    }
};