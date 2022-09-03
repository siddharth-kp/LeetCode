class Solution {
public:
    
    int diff;
    //vector<int> ans;
    set<int> sol;
    
    void solve(int i, int n, int num) // here curr digit is i
    {
        if(!n)
        {
            sol.insert(num);
            //cout<<i<<" "<<n<<" "<<num<<endl;
            return;
        }
        num=num*10+i;
        if(i+diff>=0 && i+diff<=9)
            solve(i+diff,n-1,num);
        if(i-diff>=0 && i-diff<=9)
            solve(i-diff,n-1,num);
    }
    
    vector<int> numsSameConsecDiff(int n, int k)
    {
        diff=k;
        for(int i=1;i<=9;i++)
            solve(i,n,0);
        // for(auto it = ans.begin();it!=ans.end();)
        //     if(to_string(*it).size()!=n)
        //         ans.erase(it);
        //     else
        //         it++;
        vector<int> ans;
        for(auto i:sol)
            ans.push_back(i);
        return ans;
    }
};