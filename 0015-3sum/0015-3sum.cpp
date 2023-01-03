class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        // for(int i=0;i<nums.size();i++)
        //     cout<<nums[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<nums.size();i++)
        //     cout<<i<<" ";
        // cout<<endl;
        for(int i=0;i<nums.size();i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int num=-1*nums[i];
            int left=i+1,right=nums.size()-1;
            while(left<right)
            {
                if(nums[left]+nums[right]==num)
                {
                    // cout<<i<<" "<<left<<" "<<right<<endl;
                    ans.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                }
                else if(nums[left]+nums[right]>num)
                    right--;
                else
                    left++;
            }
        }
        if(ans.size()<=1)
            return ans;
        // sort(ans.begin(),ans.end());
        for(auto it=ans.begin()+1;it!=ans.end();)
        {
            if(*it==*(it-1))
                ans.erase(it);
            else
                it++;
        }
        return ans;
    }
};