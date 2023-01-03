class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        // set<int> s;
        // for(int i=0;i<nums.size();i++)
        //     s.insert(nums[i]);
        int i=nums.size()-1;
        for(;i>0;i--)
        {
            if(nums[i-1]<nums[i])
                break;
        }
        if(i==0)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int j=nums.size()-1;j>=i;j--)
            if(nums[j]>nums[i-1])
            {
                swap(nums[j],nums[i-1]);
                sort(nums.begin()+i,nums.end());
                return;
            }
    }
};