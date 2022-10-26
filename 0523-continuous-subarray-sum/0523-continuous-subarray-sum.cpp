class Solution {
public:
    bool checkSubarraySum(vector<int>& numss, int k)
    {
        unordered_map<int,int>m;
        m[0]=-1;
        int sum=0;
        for(int i=0;i<numss.size();i++)
        {
           sum+=numss[i];
           int r=sum%k;
           if(m.find(r)!=m.end())
           {
              if(i-m[r]>1)
                  return true;
           }
           else
             m[r]=i;
        }
      return false;
    }
};