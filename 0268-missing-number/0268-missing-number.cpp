class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int zero = false;
        for(int i:nums)
            zero |= (i==0);
        if(!zero)   return 0;
        zero = 0;
        for(int i=1;i<=nums.size();i++)
            zero ^= i;
        for(int i:nums)
            zero ^= i;
        return zero;
    }
};