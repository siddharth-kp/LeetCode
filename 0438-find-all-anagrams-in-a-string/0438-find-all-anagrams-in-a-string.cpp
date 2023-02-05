class Solution {
public:
    vector<int> findAnagrams(string s, string p)
    {
        int m = s.size(), n = p.size(), i = 0; 
        if(m < n)
            return {};
        vector<char> countp(256, 0), countw(256, 0);
        vector<int> ans;
        for(;i<n;i++)
        {
            countp[p[i]]++;   
            countw[s[i]]++;
        }
        for(;i<m;i++)
        {
            if(countp == countw) ans.push_back(i-n);
            countw[s[i]]++;
            countw[s[(i-n)]]--;
        }
        if(countp == countw)
            ans.push_back(m-n);
        return ans;
        
        
        // solution #2 , TLE
    //     int pl = p.length(),sl=s.length();
    //     vector<int> ans;
    //     string p2 = p;
    //     sort(p2.begin(),p2.end());
    //     for(int i=0;i<sl-pl+1;i++)
    //     {
    //         string str = s.substr(i,pl);
    //         sort(str.begin(),str.end());
    //         if(str==p2)
    //             ans.push_back(i);
    //     }
    //     return ans;
        
        
     }
};