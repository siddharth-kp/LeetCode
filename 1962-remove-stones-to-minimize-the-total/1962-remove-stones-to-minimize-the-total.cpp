class Solution {
public:
    int minStoneSum(vector<int>& piles, int k)
    {
        priority_queue<int> pq;
        for(int i:piles)
            pq.push(i);
        while(k--)
        {
            int a=pq.top();
            pq.pop();
            pq.push(ceil(a/2.0));
        }
        int sum=0;
        while(!pq.empty())
        {
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};