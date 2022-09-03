class Solution {
public:
    int minPartitions(string n)
    {
        // int maxi=-1;
        // for(char c:n)
        //     maxi=max(maxi,c-'0');
        // return maxi;
        
        return *max_element(n.begin(),n.end())-'0';
    }
};