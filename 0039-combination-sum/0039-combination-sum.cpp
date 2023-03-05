class Solution {
public:
    
    vector<vector<int>> ans;
    
    void permute(vector<int>& candidates, int target, int idx, vector<int> temp)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<candidates.size();i++)
        {
            if(target-candidates[i]<0)
                return;
            target-=candidates[i];
            temp.push_back(candidates[i]);
            permute(candidates,target,i,temp);
            target+=candidates[i];
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        sort(candidates.begin(),candidates.end());
        permute(candidates,target,0,{});
        return ans;
    }
};