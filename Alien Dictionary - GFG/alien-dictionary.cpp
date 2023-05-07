//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dictionary[], int n, int k) {
    vector<vector<int>> adj(26);
    for(int i=1;i<n;i++)
    {
        int l=min(dictionary[i-1].size(),dictionary[i].size());
        for(int j=0;j<l;j++)
        {
            if(dictionary[i-1][j]!=dictionary[i][j])
            {
                adj[dictionary[i-1][j]-'a'].push_back(dictionary[i][j]-'a');
                // cout<<dictionary[i-1][j]<<" "<<dictionary[i][j]<<endl;
                break;
            }
        }
    }
    vector<int> ind(k,0);
    for(auto i:adj)
    for(int j:i)
    ind[j]++;
    // for(int i:ind)
    // cout<<i<<" ";
    // cout<<endl;

    vector<int> ans;
    queue<int> q;
    vector<bool> vis(k,0);
    for(int i=0;i<k;i++){
      if (ind[i] == 0) {
        q.push(i);
        ans.push_back(i);
        vis[i] = 1;
      }
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v:adj[u]){
            if(!vis[v] && ind[v]==1){
                vis[v]=1;
                q.push(v);
                ans.push_back(v);
            }
            else ind[v]--;
        }
    }
    string fin="";
    for(int i:ans)
    fin.push_back(i+'a');
    // cout<<fin<<endl;
    return fin;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends