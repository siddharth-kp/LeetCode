class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int idx =(lower_bound(nums.begin(),nums.end(),target)-nums.begin());
        // if(nums[idx]!=target)   idx--;
        // cout<<idx<<endl;
        return max(0,idx);
    }
};