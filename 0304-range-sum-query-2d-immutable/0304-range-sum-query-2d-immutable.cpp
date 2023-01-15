class NumMatrix {
private:
    vector<vector<int>> v;
    
public:    
    NumMatrix(vector<vector<int>>& matrix)
    {
        for(auto i:matrix)
            v.push_back(i);
        for(int i=0;i<v.size();i++)
            for(int j=1;j<v[0].size();j++)
                v[i][j]+=v[i][j-1];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int ans=0;
        if(col1==0)
            for(int row=row1;row<=row2;row++)
                ans+=v[row][col2];
        else
            for(int row=row1;row<=row2;row++)
                ans+=v[row][col2]-v[row][col1-1];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */