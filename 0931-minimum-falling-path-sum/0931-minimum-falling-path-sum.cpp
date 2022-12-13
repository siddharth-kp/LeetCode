class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat)
    {
        int ans = INT_MAX, n=mat.size();
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                int temp=mat[i+1][j];
                if(j>0) temp=min(temp,mat[i+1][j-1]);
                if(j<n-1) temp=min(temp,mat[i+1][j+1]);
                mat[i][j] += temp;
            }
        }
        return *min_element(mat[0].begin(),mat[0].end());
    }
};