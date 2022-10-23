class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums)
    {
        unordered_set<int> s;
        vector<int> v;
        for(int i:nums)
        {
            //cout<<i<<" "<<s.count(i)<<endl;
            if(s.count(i))
            {
                //cout<<i<<" ";
                v.push_back(i);
                break;
            }
            s.insert(i);
        }
        for(int i=0;i<nums.size();i++)    s.insert(i+1);
        for(int i:nums) s.erase(i);
        //cout<<(*s.begin());
        v.push_back(*s.begin());
        return v;
    }
};