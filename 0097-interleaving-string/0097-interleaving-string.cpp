class Solution {
private:
    string s1,s2,s3;
    int dp[201][201][201];

    bool recur(int idx1, int idx2, int idx3)
    {
        if(dp[idx1][idx2][idx3] != -1)
            return dp[idx1][idx2][idx3];
        if(s1.size()==idx1 && s2.size()==idx2)
            return dp[idx1][idx2][idx3] = true;
        else if(s1.size()==idx1)
            if(s2[idx2] == s3[idx3])
                return dp[idx1][idx2][idx3] = recur(idx1,idx2+1,idx3+1);
        else if(s2.size()==idx2)
            if(s1[idx1] == s3[idx3])
                return dp[idx1][idx2][idx3] = recur(idx1+1,idx2,idx3+1);
        bool temp=0;
        if(s1[idx1]==s3[idx3])
            temp=temp|recur(idx1+1,idx2,idx3+1);
        if(s2[idx2]==s3[idx3])
            temp=temp|recur(idx1,idx2+1,idx3+1);
        return dp[idx1][idx2][idx3] = temp;
    }

public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if(s1.size()+s2.size()!=s3.size())
            return 0;
        memset(dp,-1,sizeof(dp));
        this->s1=s1, this->s2=s2, this->s3=s3;
        return recur(0,0,0);        
    }
};