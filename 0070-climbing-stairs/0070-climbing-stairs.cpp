class Solution {
public:
    
    int recur(int n,int v[])
    {
        if(v[n]!=-1)
            return v[n];
        if(n<0)
            return 0;
        if(n<=1)
            return 1;
        v[n]=  recur(n-1,v)+recur(n-2,v);
        return v[n];
    }
    
    int climbStairs(int n) 
    {
        
        int v[n+1];
        for(int i=0;i<=n;i++)
            v[i]=-1;
        return recur(n,v);
    }
};