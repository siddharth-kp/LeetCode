class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<long long int>st;
        for(string str:tokens)
        {
            if(str=="+" || str=="-" || str=="*" || str=="/")
            {
                long long int temp1 = st.top();
                st.pop();
                long long int temp2 = st.top();
                st.pop();
                if(str=="+")
                    temp2+=temp1;
                else if(str=="-")
                    temp2-=temp1;
                else if(str=="*")
                    temp2*=temp1;
                else if(str=="/")
                    temp2/=temp1;
                st.push(temp2);
            }
            else
                st.push(stoll(str));
        }
        return st.top();
    }
};