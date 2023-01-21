class Solution {
public:
    
    vector<string> ans;
    
    void recur(string s, int left, string temp)
    {
        // cout<<s<<" "<<left<<" "<<temp<<endl;
        if(s=="" && left==0)
        {
            ans.push_back(temp.substr(1));
            return;
        }
        if(s=="" || left==0)
            return;
        for(int i=0;i<s.size();i++)
        {
            string temp2=s.substr(0,i+1);
            if(temp2.size()>1 && temp2[0]=='0')
                continue;
            if(stoi(temp2)>255)
                break;
            if(stoi(temp2)>=0)
                recur(s.substr(i+1),left-1,temp+"."+temp2);
        }
    }
    
    vector<string> restoreIpAddresses(string s)
    {
        string temp;
        recur(s,4,temp);
        return ans;
    }
};