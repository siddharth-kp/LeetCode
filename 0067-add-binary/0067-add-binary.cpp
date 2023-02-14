class Solution {
public:
    string addBinary(string a, string b) 
    {
        int n =a.size(),m=b.size();
        string s;
        int c=0;
        int i=n-1, j=m-1;
        while (i>= 0 || j >= 0 || c > 0)
        {
            if (i >= 0) 
            {
                c+= a[i] - '0';
                i-= 1;
            }
            if (j >= 0) 
            {
                c+= b[j] - '0';
                j-= 1;
            }
            s+=(c% 2) + '0';
            c/= 2;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};