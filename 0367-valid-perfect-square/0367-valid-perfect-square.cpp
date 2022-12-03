class Solution {
public:
    bool isPerfectSquare(int num)
    {
        return pow(floor(sqrt(num)),2)==num;
    }
};