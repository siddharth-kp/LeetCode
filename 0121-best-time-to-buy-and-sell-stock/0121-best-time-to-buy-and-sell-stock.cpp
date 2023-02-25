class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        vector<int> left,right;
        int temp=INT_MAX;
        for(int i=0;i<n;i++)
        {
            temp=min(temp,prices[i]);
            left.push_back(temp);
        }
        temp=INT_MIN;
        for(int i=n-1;i>=0;i--)
        {
            temp=max(temp,prices[i]);
            right.push_back(temp);
        }
        reverse(right.begin(),right.end());
        temp=INT_MIN;
        for(int i=0;i<n;i++)
            temp=max(temp,right[i]-left[i]);
        return temp;
    }
};