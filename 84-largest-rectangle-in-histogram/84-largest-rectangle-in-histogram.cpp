class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> st;
        int n = h.size(), mx = 0;
        st.push(-1);
        for(int i = 0; i <= n; i++){
            while(st.top() != -1 && (i == n || h[st.top()] > h[i])){
                int height = h[st.top()];
                st.pop();
                int rightSmallest  = i - 1, leftSmallest = st.top() + 1;
                mx = max(mx, (rightSmallest - leftSmallest + 1) * height);  
            }
            st.push(i);
        }
        return mx;
    }
};