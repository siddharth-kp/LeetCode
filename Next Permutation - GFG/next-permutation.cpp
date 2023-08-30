//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> arr){
        // vector<int> ans = arr;
        int idx=-1;
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]<arr[i+1])
            {
                idx = i;
                break;
            }
        }
        if(idx==-1)
        {
            sort(arr.begin(),arr.end());
            return arr;
        }
        int mini_idx=-1, mini_val=INT_MAX;
        for(int i=idx+1;i<n;i++)
        {
            if(arr[i]>arr[idx] && arr[i]<mini_val)
            {
                mini_val=arr[i];
                mini_idx=i;
            }
        }
        swap(arr[idx], arr[mini_idx]);
        sort(arr.begin()+idx+1,arr.end());
        return arr;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends