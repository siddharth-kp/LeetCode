// class Solution {
// private:
//     vector<int> dp, beg;
//     vector<vector<int>> offers;

//     void pnt()
//     {
//         for(vector<int> v:offers)
//         {
//             for(int i:v)
//             cout<<i<<" ";
//             cout<<endl;
//         }
//         cout<<endl;
//     }

//     int recur(int idx)
//     {
//         cout<<idx<<endl;
//         if(idx>=beg.size())
//             return 0;
//         if(dp[idx]!=-1)
//             return dp[idx];
//         int idx2 = lower_bound(beg.begin(), beg.end(), offers[idx][1]+1)-beg.begin();
//         cout<<idx<<" "<<idx2<<endl;
//         // if(idx2==beg.size())
//         //     return dp[idx]=offers[idx][2];
//         int take = offers[idx][2] + recur(idx2);
//         int not_take = recur(idx+1);
//         return dp[idx]=max(take,not_take);
//     }
    
// public:
//     int maximizeTheProfit(int n, vector<vector<int>>& offers)
//     {
//         dp.resize(n,-1);
//         beg.resize(offers.size());
//         sort(offers.begin(),offers.end());
//         this->offers=offers;
//         for(int i=0;i<offers.size();i++)
//             beg[i]=offers[i][0];
//         pnt();
//         return recur(0);
//     }
// };

// /*

// */

class Solution {
public:
    vector<int>temp,dp;
    int fn(int ind,vector<vector<int>>&offers)
    {
        if(ind>=offers.size())return 0;     
        if(dp[ind]!=-1)return dp[ind];    
        int non_take=fn(ind+1,offers);  
        int target=lower_bound(temp.begin(),temp.end(),offers[ind][1]+1)-temp.begin();
        int take=offers[ind][2]+fn(target,offers);  
        return dp[ind]=max(non_take,take);
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(),offers.end());
        for(auto it:offers)
            temp.push_back(it[0]);
			
        dp.resize(offers.size(),-1);
        return fn(0,offers);
    }
};