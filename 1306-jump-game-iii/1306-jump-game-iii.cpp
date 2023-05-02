// Memoization

class Solution {
public:
    
    bool recur(int idx, vector<int> &arr, vector<int> &dp, vector<bool> &visited)
    {
        if(arr[idx]==0)
            return dp[idx]=1;
        if(visited[idx]==1)
            return dp[idx];
        visited[idx]=1;
        bool a=0,b=0;
        if(idx+arr[idx]>=0 && idx+arr[idx]<arr.size())
            a= recur(idx+arr[idx],arr,dp,visited);
        if(idx-arr[idx]>=0 && idx-arr[idx]<arr.size())
            b= recur(idx-arr[idx],arr,dp,visited);
        return dp[idx]=a|b;
    }
    
    bool canReach(vector<int>& arr, int start)
    {
        bool possible = false;
        for(int i:arr)
            if(i==0)
                possible=1;
        if(possible==0)
            return 0;
        
        vector<int> dp(arr.size(),0);
        vector<bool> visited(arr.size(),0);
        return recur(start,arr,dp,visited);
    }
};


// Tabulation

// class Solution {
// public:
//     bool canReach(vector<int>& arr, int start)
//     {
        
//     }
// };