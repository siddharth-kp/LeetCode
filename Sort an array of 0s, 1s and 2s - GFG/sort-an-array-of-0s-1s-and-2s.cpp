//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int nums[], int l)
    {
        //int l = nums.size();
        int begin=0, end=l-1;
        for(int i=0;i<l;)
        {
            if(nums[i]==0 && begin<i)
                swap(nums[i],nums[begin++]);
            else if(nums[i]==2 && end>i)
                swap(nums[i],nums[end--]);
            else
                i++;
        }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends