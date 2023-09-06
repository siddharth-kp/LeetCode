class Solution {
public:
    int findTheWinner(int n, int k)
    {
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            arr[i]=i;
        int curr=0;
        while(arr.size()!=1)
        {
            curr+=k-1;
            curr%=arr.size();
            arr.erase(arr.begin()+curr);
        }
        return arr[0]+1;
    }
};