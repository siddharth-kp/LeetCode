// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums)
//     {
//         vector<vector<int>> ans;
//         sort(nums.begin(),nums.end());
//         // for(int i=0;i<nums.size();i++)
//         //     cout<<nums[i]<<" ";
//         // cout<<endl;
//         // for(int i=0;i<nums.size();i++)
//         //     cout<<i<<" ";
//         // cout<<endl;
//         for(int i=0;i<nums.size();i++)
//         {
//             if(i>0 && nums[i]==nums[i-1])
//                 continue;
//             int num=-1*nums[i];
//             int left=i+1,right=nums.size()-1;
//             while(left<right)
//             {
//                 if(nums[left]+nums[right]==num)
//                 {
//                     // cout<<i<<" "<<left<<" "<<right<<endl;
//                     ans.push_back({nums[i],nums[left],nums[right]});
//                     left++;
//                     right--;
//                 }
//                 else if(nums[left]+nums[right]>num)
//                     right--;
//                 else
//                     left++;
//             }
//         }
//         if(ans.size()<=1)
//             return ans;
//         // sort(ans.begin(),ans.end());
//         for(auto it=ans.begin()+1;it!=ans.end();)
//         {
//             if(*it==*(it-1))
//                 ans.erase(it);
//             else
//                 it++;
//         }
//         return ans;
//     }
// };



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());     //Sorted Array
        if(nums.size() < 3){                // Base Case 1
            return {};
        }
        if(nums[0] > 0){                    // Base Case 2
            return {};
        }
        unordered_map<int , int> hashMap;
        for(int i = 0 ; i < nums.size() ; ++i){     //Hashing of Indices
            hashMap[nums[i]] = i;
        }
        vector<vector<int>> answer;
        for(int i = 0 ; i < nums.size() - 2 ; ++i){     //Traversing the array to fix the number.
            if(nums[i] > 0){     //If number fixed is +ve, stop there because we can't make it zero by searching after it.
                break;
            }
            for(int j = i + 1 ; j < nums.size() - 1 ; ++j){     //Fixing another number after first number
                int required = -1*(nums[i] + nums[j]);    //To make sum 0, we would require the -ve sum of both fixed numbers.
                if(hashMap.count(required) && hashMap.find(required)->second > j){ //If it exists in hashmap and its last occurrence index > 2nd fixed index, we found our triplet.
                    answer.push_back({nums[i] , nums[j] , required});
                }
                j = hashMap.find(nums[j])->second; //Update j to last occurence of 2nd fixed number to avoid duplicate triplets.
            }
            i = hashMap.find(nums[i])->second;     //Update i to last occurence of 1st fixed number to avoid duplicate triplets.
        }
        return answer;  //Return answer vector.
    }
};