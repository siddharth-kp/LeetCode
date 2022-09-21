class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int s=0;
        vector<int> v;
        for(auto x:A)
            if(x%2==0) s+=x;
        for(int i=0;i<queries.size();i++)
        {
            
            int add=queries[i][0];
            int idx=queries[i][1];
            int p=A[idx];
            A[idx]+=add;
            if(p%2==0)
            {
                if(A[idx]%2==0)
                {
                     s-=p;
                    s+=A[idx];
                    v.push_back(s);
                }
                else
                {
                    s-=p; 
                    v.push_back(s); 
                }
            }
            else
            {
               if(A[idx]%2==0)
                {
                     
                    s+=A[idx];
                    v.push_back(s);
                }
                else                     
                    v.push_back(s); 
            }
        }
        return v;
    }
};