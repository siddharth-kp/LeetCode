// class Solution {
// public:
    
//     vector<int> dp;
//     unordered_map<int,vector<int>> mp;
//     unordered_set<int> visited;
    
//     int recur(int idx, vector<int> &arr)
//     {
//         cout<<idx<<"   ";
//         for(auto it:visited)
//             cout<<it<<" ";
//         cout<<endl;
//         if(visited.count(idx))
//             return INT_MAX-1;
//         if(dp[idx]!=-1)
//             return dp[idx];
//         if(idx==arr.size()-1)
//             return dp[idx]=0;
//         visited.insert(idx);
//         int fwd=(idx<arr.size()-1)?recur(idx+1,arr):INT_MAX-1;
//         int bck=(idx>0)?recur(idx-1,arr):INT_MAX-1;
//         int mini=INT_MAX-1;
//         for(int i:mp[arr[idx]])
//             mini=min(mini,recur(i,arr));
//         visited.erase(idx);
//         return dp[idx]=min(min(fwd,bck),mini)+1;
//     }
    
//     int minJumps(vector<int>& arr)
//     {
//         dp.resize(arr.size(),-1);
//         for(int i=0;i<arr.size();i++)
//             mp[arr[i]].push_back(i);
//         for(auto it:mp)
//         {
//             cout<<it.first<<"    ";
//             for(int i:it.second)
//                 cout<<i<<" ";
//             cout<<endl;
//         }        
//         return recur(0,arr);
//     }
// };



class Solution {
public:
    
    int minJumps(vector<int>& arr)
    {
        vector<bool> visited(arr.size(),0);
        queue<int> q;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<arr.size();i++)
            mp[arr[i]].push_back(i);
        q.push(0);
        int steps=0;
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                int u=q.front();
                q.pop();
                if(u==arr.size()-1)
                    return steps;
                if(u>0 && !visited[u-1])
                {
                    q.push(u-1);
                    visited[u-1]=1;
                }
                if(u<arr.size()-1 && !visited[u+1])
                {
                    visited[u+1]=1;
                    q.push(u+1);
                }
                for(int i:mp[arr[u]])
                    if(!visited[i])
                    {
                        q.push(i);
                        visited[i]=1;
                    }
                mp[arr[u]].clear();
            }
            steps++;
        }
        return -1;
    }
};
