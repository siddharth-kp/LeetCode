class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left;
        vector<int> right;

        int maxi = 0;
        for(int i=0; i<height.size(); i++) {
            left.push_back(maxi);
            maxi = max(maxi, height[i]);
        }

        maxi = 0;
        for(int j=height.size()-1; j>=0 ; j--) {
            right.push_back(maxi);
            maxi = max(maxi, height[j]);
        }
        reverse(right.begin(), right.end());

        int ans = 0;

        for(int i=0; i<height.size(); i++) {

            int lvl = min(left[i], right[i]) - height[i];
            if(lvl>0) ans+= lvl;
        }

        return ans;
    }
};