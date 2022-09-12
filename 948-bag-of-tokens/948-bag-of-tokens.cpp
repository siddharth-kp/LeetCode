class Solution {
public:
    
    int score=0;
    int max_score=0;
    
    bool check(int &power, vector<int> &tokens)
    {
        if(tokens.size()<=0)
            return 0;
        if(power>=tokens[0])
            return 1;
        if(score>0)
            return 1;
        return 0;
    }
    
    void operate(int &power, vector<int> &tokens)
    {
        if(tokens.size()<=0)
            return;
        //cout<<power<<" "<<tokens[0]<<"    ";
        if(power>=tokens[0])
        {
            power-=tokens[0];
            tokens.erase(tokens.begin());
            score+=1;
            max_score=max(score,max_score);
        }
        else if(score>0)
        {
            power+=tokens[tokens.size()-1];
            score-=1;
            tokens.erase(tokens.end()-1);
            max_score=max(score,max_score);
            
        }
        //cout<<" power now is "<<power<<endl;
    }
    
    int bagOfTokensScore(vector<int>& tokens, int power)
    {
        sort(tokens.begin(),tokens.end());
        int index=0;
        while(check(power,tokens))
            operate(power,tokens);
        return max_score;
    }
};