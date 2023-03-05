class Solution {
public:
    
    vector<vector<int>> ans;
    
    void permute(vector<int> candidates, int target, int idx, vector<int> temp)
    {
        if(target==0)
            ans.push_back(temp);
        if(idx==candidates.size() || target<=0)
            return;
        for(int i=idx;i<candidates.size();i++)
        {
            if(i>idx && candidates[i]==candidates[i-1])
                continue;
            target-=candidates[i];
            temp.push_back(candidates[i]);
            permute(candidates,target,i+1,temp);
            target+=candidates[i];
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(),candidates.end());
        permute(candidates,target,0,{});
        // for(vector<int> &v:ans)
        //     sort(v.begin(),v.end());
        // sort(ans.begin(),ans.end());
        // for(int i=1;i<ans.size();)
        //     if(ans[i]==ans[i-1])
        //         ans.erase(ans.begin()+i);
        //     else
        //         i++;
        return ans;
    }
};