class Solution {
public:
    int minimumLines(vector<vector<int>>& nums)
    {
        if(nums.size()==1)
            return 0;
        sort(nums.begin(),nums.end());
        vector<long double> slopes;
        long double c=1.000000000000;
        for(int i=1;i<nums.size();i++)
            slopes.push_back((nums[i][1]-nums[i-1][1])/(c*(nums[i][0]-nums[i-1][0])));
        int ans=1;
        for(int i=1;i<slopes.size();i++)
            if(slopes[i]!=slopes[i-1])
                ans++;
        return ans;
    }
};