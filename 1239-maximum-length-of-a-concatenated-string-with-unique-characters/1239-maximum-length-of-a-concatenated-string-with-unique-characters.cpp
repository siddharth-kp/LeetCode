class Solution {
private:
    void solve(const vector<string>& arr, int index, int& max_len, string str, vector<int>& char_count)
    {
        max_len = max(max_len, static_cast<int>(str.size()) );
        for (int i = index, j; i < arr.size(); i++)
        {
            for (j = 0; j < arr[i].size(); j++)
                if (char_count[arr[i][j] - 'a']++ != 0)
                    break;
            if (j == arr[i].size())
                solve(arr, i + 1, max_len, str + arr[i], char_count), --j;
            while (j >= 0)
                --char_count[arr[i][j--] - 'a'];
                
        }
    }
    
public:
    int maxLength(vector<string>& arr)
    {
        int max_len = 0;
        vector<int> count(26, 0);
        solve(arr, 0, max_len, "", count);
        return max_len;
    }
    

};