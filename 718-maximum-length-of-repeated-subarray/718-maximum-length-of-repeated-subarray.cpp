class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2)
    {
        if (nums1.size()<nums2.size()) swap(nums1,nums2);
        int l1=nums1.size(), l2=nums2.size();
        vector<int> dp(l2+1,0);
        int ans=0;
        for(int i=0;i<l1;i++)
        {
            for(int j=l2-1;j>=0;j--)
            {    
                if (nums1[i] == nums2[j])
                    dp[j + 1] = 1 + dp[j];
                else
                    dp[j + 1] = 0;
                ans = max(ans,dp[j+1]);
            }
        }
        return ans;
    }
};