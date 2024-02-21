class Solution {
public:
    int rangeBitwiseAnd(int l, int r) 
    {
        return (l && l != r)?(rangeBitwiseAnd(l>>1, r>>1)<<1) : l;
    }
};