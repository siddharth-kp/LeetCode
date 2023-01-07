class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        long long int total =0,diff=0;
        int start=0,current=0;
        for(int i=0;i<gas.size();i++)
        {
            diff=gas[i]-cost[i];
            total+=diff;
            current+=diff;
            if(current<0)
            {
                start=i+1;
                current=0;
            }
        }
        if(total<0)
            return -1;
        return start;
    }
};