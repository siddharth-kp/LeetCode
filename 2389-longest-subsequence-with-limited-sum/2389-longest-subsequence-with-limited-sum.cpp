class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries)
    {
        int n=nums.size();
        int m=queries.size();
        sort(nums.begin(),nums.end());
        vector<int>psum(n);
        vector<int>ans(m);
        psum[0]=nums[0];
        for(int i=1;i<nums.size();i++)
            psum[i]=nums[i]+psum[i-1];
        for(int i=0;i<m;i++)
        {
            int ind= upper_bound(psum.begin(),psum.end(),queries[i])-psum.begin();
            ans[i]=ind;
        }
        return ans;
    }
};