class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix)
    {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            int row=0,column=i;
            while(row+1<n && column+1<m)
                if(matrix[row][column]!=matrix[++row][++column])
                    return false;
        }
        for(int i=0;i<n;i++)
        {
            int row=i,column=0;
            while(row+1<n && column+1<m)
                if(matrix[row][column]!=matrix[++row][++column])
                    return false;
        }
        return true;
    }
};