class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        int prevTarget = INT_MIN;
        for(int i=0; i<nums.size()-2; i++) {
            int target = -nums[i];
            if(target==prevTarget) continue;
            else prevTarget = target;
            int p1 = i+1, p2 = nums.size()-1;
            pair<int, int> prev = {INT_MIN, INT_MIN};
            while(p1<p2) {
                int sum = nums[p1] + nums[p2];
                if(sum>target) p2--;
                else if(sum<target) p1++;
                else {
                    vector<int> v;
                    v.push_back(nums[i]);
                    if(prev.first==nums[p1] && prev.second==nums[p2]) {

                    } else {
                        prev.first = nums[p1];
                        prev.second = nums[p2];
                        v.push_back(nums[p1]);
                        v.push_back(nums[p2]);
                        ans.push_back(v);
                    }
                    
                    p1++; p2--;
                    
                }
            }
        }
        return ans;
    }
};