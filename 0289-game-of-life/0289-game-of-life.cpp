class Solution {
private:
    vector<vector<int>> board, new_board;
    
    void modify(int row, int col)
    {
        int live=0;
        if(row!=0)  live += board[row-1][col];
        if(col!=0)  live += board[row][col-1];
        if(row!=board.size()-1)  live += board[row+1][col];
        if(col!=board[0].size()-1)  live += board[row][col+1];
        if(row!=0 && col!=0) live += board[row-1][col-1];
        if(row!=0 && col!=board[0].size()-1) live += board[row-1][col+1];
        if(row!=board.size()-1 && col!=0) live += board[row+1][col-1];
        if(row!=board.size()-1 && col!=board[0].size()-1) live += board[row+1][col+1];
        if(board[row][col]==1)
            new_board[row][col] = (live==2 || live==3);
        else
            new_board[row][col] = (live==3);
    }
    
public:
    void gameOfLife(vector<vector<int>>& board)
    {
        this->board=board;
        new_board=board;
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                modify(i,j);
        board=new_board;
    }
};