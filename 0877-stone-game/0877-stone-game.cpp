class Solution {
// private:
//     map<pair<int,int>,int> mp;
    
//     bool recur(vector<int> &piles, int left, int right, int alice, int sum)
//     {
//         // cout<<left<<" "<<right<<endl;
//         if(left>=right)
//             return false;
//         if(left+1==right)
//             return mp[{left,right}]=1;
//         if(mp.count({left,right}))
//             return mp[{left,right}];
//         bool l = recur(piles,left+1,right,1-alice,sum+piles[left]*(alice?1:-1));
//         bool r = recur(piles,left,right-1,1-alice,sum+piles[right]*(alice?1:-1));
//         return mp[{left,right}]=l|r;
//     }
    
// public:    
//     bool stoneGame(vector<int>& piles)
//     {
//         int alice=1, sum=0;
//         int left=0, right=piles.size()-1;
//         return recur(piles,left,right,1,0);
//     }
    
    
 public:    
    bool stoneGame(vector<int>& piles)
    {
        return 1;
    }
};