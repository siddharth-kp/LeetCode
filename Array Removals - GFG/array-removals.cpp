//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    int k2;
    
    int solve(vector<vector<int>> &v, vector<int> &arr, int left, int right)
    {
        if(arr[right]-arr[left]<=k2)  return 0;
        if(v[left][right]!=-1)  return v[left][right];
        return v[left][right]=1+min( solve(v,arr,left,right-1),solve(v,arr,left+1,right) );
    }
    
    int removals(vector<int>& arr, int k)
    {
        vector<vector<int>> v(arr.size()+1,vector<int> (arr.size()+1,-1));
        k2=k;
        sort(arr.begin(),arr.end());
        int left=0,right=arr.size()-1;
        return solve(v,arr,left,right);
        //return right+1-range;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends