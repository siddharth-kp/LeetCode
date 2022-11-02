class Solution {
    
private:
    bool isMutation(string& s, string& t)
    {
        int changes = 0;
        for(int i = 0; i<8; i++)    if(s[i] != t[i]) changes++;
        return changes == 1;
    }
        
public:
    int minMutation(string start, string end, vector<string>& bank)
    {
        int result = 0;
        queue< pair<string, set<string>> >q;
        q.push({start, {start}});
        
        while(!q.empty())
        {
            int qLen = q.size();
            while(qLen--)
            {
                auto front = q.front();     q.pop();
                string curr = front.first;
                set<string> visited = front.second;
                if(curr == end) return result;
                for(int i = 0;  i<bank.size(); i++)
                {
                    if(isMutation(bank[i], curr) && visited.count(bank[i]) == 0)
                    {
                        set<string> temp = visited;
                        temp.insert(bank[i]);
                        q.push({bank[i], temp});
                    }
                }
            }
            if(q.size())    result++; 
        }
        return -1;
    }   
};