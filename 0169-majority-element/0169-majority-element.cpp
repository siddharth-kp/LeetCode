class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int elem=0, count=0;
        for(auto i:nums)
        {
            if(count==0)
                elem=i;
            if(elem==i)
                count++;
            else
                count--;
        }
        return elem;
    }
};