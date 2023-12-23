class Solution {
public:
    bool isPathCrossing(string path)
    {
        pair<int,int> pos = {0,0};
        set<pair<int,int>> st;
        st.insert(pos);
        for(char c:path)
        {
            if(c=='N')
                pos.second += 1;
            else if(c=='S')
                pos.second -= 1;
            else if(c=='E')
                pos.first += 1;
            else
                pos.first -= 1;
            if(st.count(pos))
                return 1;
            else
                st.insert(pos);
        }
        return 0;
    }
};