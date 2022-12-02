// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n)
    {
        long long int start=1,end=n;
        long long int mid=(start+end)/2;
        while(start<end)
        {
            mid=(start+end)/2;
            if(isBadVersion(mid))
                end=mid-1;
            else
                start=mid+1;
        }
        //cout<<mid<<endl;
        if(isBadVersion(mid-1))
            return mid-1;
        else if(isBadVersion(mid))
            return mid;
        else if(isBadVersion(mid+1))
            return mid+1;
        else
            return mid+2;
    }
};