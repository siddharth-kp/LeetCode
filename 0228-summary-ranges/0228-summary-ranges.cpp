class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        vector<string> v;
        if(nums.size()==0)
            return v;
        if (nums.size()==1)
        {
            return {to_string(nums[0])};
        }
        
        long int start=0,end=0;
        int l =nums.size();
        for(long int i=1;i<l;i++)
        {
            if(nums[i]==nums[i-1]+1)
            {
                end++;
            }
            else
            {
                if(start==end)
                {
                    v.push_back(to_string(nums[start]));
                    start++;end++;
                }
                else
                {
                    v.push_back(
                        to_string(nums[start])+"->"+to_string(nums[end])
                    );
                    start=end+1;
                    end=start;
                }
            }
        }
        if(start==end)
            v.push_back(to_string(nums[start]));
        else
            v.push_back(
                        to_string(nums[start])+"->"+to_string(nums[end])
                    );
        return v;
    }
};