class Solution {
public:
    int numSpecial(vector<vector<int>>& mat)
    {
        vector<int> rowsum(mat.size(),0), colsum(mat[0].size(),0);
        for(int i=0;i<mat.size();i++)
            for(int j:mat[i])
                rowsum[i]+=j;
        for(int i=0;i<mat[0].size();i++)
            for(int j=0;j<mat.size();j++)
                colsum[i] += mat[j][i];
        // for(int i:rowsum)   cout<<i<<" ";cout<<endl;
        // for(int i:colsum)   cout<<i<<" ";cout<<endl;
        int ans = 0;
        for(int i=0;i<mat.size();i++)
            for(int j=0;j<mat[0].size();j++)
                ans += (rowsum[i]==1 && colsum[j]==1 && mat[i][j]);
        return ans;
    }
};