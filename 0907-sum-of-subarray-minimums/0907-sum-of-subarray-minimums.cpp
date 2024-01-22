class Solution {
private:
    int mod = 1e9+7;
    
    vector<int> nese(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> result(n, n);
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[i] < arr[st.top()])
            {
                result[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
    
    vector<int> pese(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> result(n, -1);
        stack<int> st;
        for(int i=0;i<n;++i)
        {
            while(!st.empty() && arr[i] < arr[st.top()])
                st.pop();
            if(!st.empty())
                result[i] = st.top();
            st.push(i);
        }
        return result;
    }
    
    void pnt(vector<int> &arr)
    {
        for(int i:arr)  cout<<i<<" ";
        cout<<endl;
    }
    
public:
    int sumSubarrayMins(vector<int>& arr)
    {
        vector<int> nse = nese(arr);
        vector<int> pse = pese(arr);
        long long int ans = 0;
        for(int i=0;i<arr.size();i++)
        {
            ans += ((long long)arr[i])*(i-pse[i])*(nse[i]-i);
            ans%=mod;
        }
        return ans;
    }
};