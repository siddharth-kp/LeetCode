class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int ind=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(ind==nums.size() || nums[ind]!=target)
            return {-1,-1};
        int ind2=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        ind2--;
        if(ind2==-1 || nums[ind2]!=target)
            return {ind,ind};
        else
            return {ind,ind2};
    }
};