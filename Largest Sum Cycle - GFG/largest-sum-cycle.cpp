//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  
//   long long dfs(int source, vector<vector<int>> &graph, vector<bool> &visited)
//   {
//       if(visited[source])
//       return INT_MIN;
//       visited[source]=1;
//       long long ans=0;
//       for(int i:graph[source])
//       {
//           if(i==-1)
//             return INT_MIN;
//           if(!visited[i])
//             ans=max(ans,dfs(i,graph,visited));
//       }
//       return source+ans;
//   }
  
//   long long largestSumCycle(int n, vector<int> Edge)
//   {
//       vector<vector<int>> graph(n);
//       for(int i=0;i<n;i++)
//       {
//           graph[i].push_back(Edge[i]);
//       }
//       vector<bool> visited(n,false);
//       long long maxsum=-1;
//       for(int i=0;i<n;i++)
//       {
//           if(!visited[i])
//           maxsum=max(maxsum,dfs(i,graph,visited));
//       }
//       return maxsum;

    // vector<bool> visited;
    // vector<int> arr;
    // unordered_set<long long> currset;
    // // vector<long long> dp;
    // long long currsum=0;
    // long long ans=-1;
    
    // void dfs(int source)
    // {
    //     if(source==-1 || arr[source]==-1)
    //     return;
    //     currsum+=arr[source];
    //     if(currset.count(source))
    //     {
    //         currsum-=arr[source];
    //         ans=max(ans,currsum);
    //         return;
    //     }
    //     visited[source]=1;
    //     if(!visited[arr[source]])
    //     dfs(arr[source]);
    // }
    
    // long long largestSumCycle(int n, vector<int> edge)
    // {
    //     visited.resize(n,0);
    //     arr=edge;
    //     for(int i=0;i<n;i++)
    //     {
    //         currset.clear();
    //         currsum=0;
    //         dfs(i);
    //         visited.resize(n,0);
    //     }
    //     return ans;
    // }
    vector<vector<int>> v;
    vector<int> vis,par,tmp;
    
    long long dfs(int node,int p=-1)
    {
        vis[node]=1;
        par[node]=p;
        tmp.push_back(node);
        for(auto i:v[node])
        {
            if(vis[i]==0)
            {
                long long z=dfs(i,node);
                if(z!=-1)
                    return z;
                
            }
            else if(vis[i]==1)
            {
                long long sum=i;
                while(node!=i)
                {
                    sum+=node;
                    node=par[node];
                }
                if(node==i)
                return sum;
                return -1;
            }
        }
        return -1;

  }
  long long largestSumCycle(int N, vector<int> Edge)
  {
      long long ans=-1;
      vis=vector<int>(N);
      v=vector<vector<int>>(N);
      par=vector<int>(N);
      for(int i=0;i<N;i++)
      {
          if(Edge[i]!=-1)
              v[i].push_back(Edge[i]);
      }
      for(int i=0;i<N;i++)
      {
          if(!vis[i])
          {
              ans=max(ans,dfs(i));
              for(auto j:tmp)
                  vis[j]=2;
              tmp.clear();
          }
      }
      return ans;
 }
};


//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends