class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        vector<int> res(temperatures.size());
        stack<int> st;
        for(int i=temperatures.size()-1;i>=0;i--)
        {
            while(st.size() && temperatures[st.top()]<=temperatures[i])
                st.pop();
            if(st.size())
                res[i]=st.top()-i;
            else
                res[i]=0;
            st.push(i);
        }
        return res;
    }
};