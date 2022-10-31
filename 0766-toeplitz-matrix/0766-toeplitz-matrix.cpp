class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix)
    {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<m;i++) // 1st row, ith column
        {
            int row=0,column=i;
            while(row+1<n && column+1<m)
            {
                if(matrix[row][column]!=matrix[row+1][column+1])
                    return false;
                row++;
                column++;
            }
        }
        for(int i=0;i<n;i++) // 1st column ith row
        {
            int row=i,column=0;
            while(row+1<n && column+1<m)
            {
                if(matrix[row][column]!=matrix[row+1][column+1])
                    return false;
                row++;
                column++;
            }
        }
        return true;
    }
};