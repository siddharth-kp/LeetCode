class Solution {
public:
    int minimumDeviation(vector<int>& nums)
    {
        priority_queue<int> pq;
        int minval = INT_MAX;
        for(int num:nums)
        {
            if(num%2)
                num*=2;
            pq.push(num);
            minval=min(minval, num);
        }
        int mini = INT_MAX;
        while(1)
        {
            int maxval = pq.top();
            pq.pop();
            mini = min(mini, maxval-minval);
            if(maxval%2==1)
                break;
            maxval=maxval/2;
            minval=min(minval, maxval);
            pq.push(maxval);
        }
        return mini;
    }
};