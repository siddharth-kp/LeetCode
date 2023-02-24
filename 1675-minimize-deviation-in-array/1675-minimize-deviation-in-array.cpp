class Solution {
public:
    int minimumDeviation(vector<int>& nums)
    {
        priority_queue<int> pq;
        int minVal = INT_MAX;
        for(int num : nums)
        {
            if (num % 2 == 1)
                num = num * 2;
            pq.push(num);
            minVal = min(minVal, num);
        }
        int mini = INT_MAX;
        while(1)
        {
            int maxVal = pq.top();
            pq.pop();
            mini = min(mini, maxVal-minVal);
            if(maxVal%2==1)
                break;
            maxVal=maxVal/2;
            minVal=min(minVal, maxVal);
            pq.push(maxVal);
        }
        return mini;
    }
};