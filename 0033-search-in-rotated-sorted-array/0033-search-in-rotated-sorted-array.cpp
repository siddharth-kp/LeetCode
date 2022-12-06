class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int left=0,right=nums.size()-1;
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(target==nums[mid])
                return mid;
            if(nums[mid]>nums[left]) // left subarray is sorted
            {
                if(target>=nums[left] && target<=nums[mid-1])
                    right=mid-1;
                else
                    left=mid+1;
            }
            else
            {
                if(target>=nums[mid+1] && target<=nums[right])
                    left=mid+1;
                else
                    right=mid-1;
            }
        }
        return nums[left]==target?left:-1;;
    }
};