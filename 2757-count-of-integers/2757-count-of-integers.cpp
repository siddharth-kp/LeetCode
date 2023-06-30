#define ll long long
class Solution {
    ll mod = 1e9 + 7;
    vector<vector<vector<ll>>> dp;
    ll recur(ll i, bool tight, ll sum, string &s){
        ll n = s.size();
        if(i == n){
            if(sum >= 0)
                return 1;
            else return 0;
        }
        if(dp[i][tight][sum] != -1)
            return dp[i][tight][sum];
        cout<<i<<' ';
        bool newtight;
        int ub = tight ? s[i] - '0' : 9;
        ll ans = 0;
        for(int j = 0; j <= ub; j++){
            newtight = (j == s[i] - '0') ? tight : false;
            if(sum >= j)
                ans = (ans + recur(i+1, newtight, sum-j, s)) % mod;
        }
        return dp[i][tight][sum] = ans;
    }
public:
    string minus1(string x){
        int i = x.size()-1;
        while(i >= 0){
            if(x[i] == '0'){
                x[i] = '9';
                i--;
            }else
                break;
        }
        x[i] -= 1;
        return x;
    }
    int count(string num1, string num2, int min_sum, int max_sum)
    {
        num1 = minus1(num1);
        cout<<num1<<'\n';
        int maxlen = max(0LL+num1.size(), 0LL+num2.size());
        dp = vector(maxlen+1, vector(2, vector<ll>(401, -1)));
        ll cntmaxnum2 = recur(0, true, max_sum, num2);
        dp = vector(maxlen+1, vector(2, vector<ll>(401, -1)));
        ll cntminnum2 = recur(0, true, min_sum-1, num2);
        dp = vector(maxlen+1, vector(2, vector<ll>(401, -1)));
        ll cntmaxnum1 = recur(0, true, max_sum, num1);
        dp = vector(maxlen+1, vector(2, vector<ll>(401, -1)));
        ll cntminnum1 = recur(0, true, min_sum-1, num1);
        return ((cntmaxnum2 - cntminnum2 + mod) % mod - (cntmaxnum1 - cntminnum1 + mod) % mod + mod) % mod;
    }
};