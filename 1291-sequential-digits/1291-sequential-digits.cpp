class Solution {
public:
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> ans;
        for(int len=2;len<=9;len++)
        {
            for(int st=1;st<=10-len;st++)
            {
                int curr = 0;
                for(int j=st;j<st+len;j++)
                    curr = curr*10 + j;
                if(curr>=low && curr<=high)
                    ans.push_back(curr);
            }
        }
        return ans;
    }
};