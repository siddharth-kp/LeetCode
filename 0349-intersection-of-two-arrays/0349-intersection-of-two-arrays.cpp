class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st, st2;
        for(int i:nums1)
            st.insert(i);
        vector<int> ans;
        for(int i:nums2)
            if(st.count(i))
                st2.insert(i);
        for(auto i:st2)
            ans.push_back(i);
        return ans;
    }
};