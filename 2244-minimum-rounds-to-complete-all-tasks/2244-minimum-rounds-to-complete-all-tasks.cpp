class Solution {
public:
    int minimumRounds(vector<int>& tasks)
    {
        unordered_map<int,int> m;
        for(int i:tasks)
            m[i]++;
        int sum=0;
        for(auto [i,j]:m)
        {
            if(j==1)
                return -1;
            sum+=(j+2)/3;
        }
        return sum;
    }
};

// 2-1;
// 3-1;



// 4-2;
// 5-2;
// 6-2;
// 7-3;
// 8-3;
// 9-3;
