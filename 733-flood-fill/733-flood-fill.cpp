class Solution {
public:
    
    vector<vector<bool>> v;
    int original,changed;
    
    void solve(vector<vector<int>> &image, int row, int col)
    {
        if(v[row][col]) return;
        image[row][col]=changed;
        v[row][col]=1;
        if(row>0 && image[row-1][col]==original)    solve(image,row-1,col);
        if(row<v.size()-1 && image[row+1][col]==original)    solve(image,row+1,col);
        if(col>0 && image[row][col-1]==original)    solve(image,row,col-1);
        if(col<v[0].size()-1 && image[row][col+1]==original)    solve(image,row,col+1);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        v.resize(image.size(),vector<bool>(image[0].size(),false));
        original = image[sr][sc], changed = color;
        solve(image,sr,sc);
        return image;
    }
};