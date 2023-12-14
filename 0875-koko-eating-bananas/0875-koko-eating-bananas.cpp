#define ll int64_t

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h)
    {
        ll low=1, high=1e9;
        while(low<high)
        {
            ll mid = low + (high-low)/2;
            ll hours=0;
            for(int i:piles)
                hours += i<mid?1:ceil(i/(double)mid);
            if(hours>h)
                low=mid+1;
            else
                high=mid-1;
        }
        ll hours=0;
        for(int i:piles)
            hours += i<low?1:ceil(i/(double)low);
        if(hours>h)
            return low+1;
        else
            return low;
    }
};