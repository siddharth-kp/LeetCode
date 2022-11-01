class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid)
    {
        vector<int> ans;
        int pos=0;
        for(int col=0;col<grid[0].size();col++)
        {
            int pos=col;
            bool flag=false;
            for(int row=0;row<grid.size();row++)
            {
                int new_pos=pos;
                if(grid[row][pos]==1)
                    new_pos++;
                else
                    new_pos--;
                if(new_pos<0 || new_pos>=grid[0].size())
                {
                    flag=true;
                    break;
                }
                if(pos<grid[0].size()-1 && grid[row][pos]==1 && grid[row][pos+1]==-1)
                {
                    flag=true;
                    break;
                }
                else if(pos>0 && grid[row][pos]==-1 && grid[row][pos-1]==1)
                {
                    flag=true;
                    break;
                }
                pos=new_pos;
                //cout<<"ok ";
            }
            ans.push_back(flag?-1:pos);
            //cout<<endl;
        }
        return ans;
    }
};