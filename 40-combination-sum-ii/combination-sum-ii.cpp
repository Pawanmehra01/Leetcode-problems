class Solution {
public:
    vector<int>ans ;
    void sumtwo(vector<int>& nums, vector<vector<int>>&res ,int target ,int n  , int  i,int sum){
        if (sum == target) {
            res.push_back(ans);
            return;
        }

        if (sum > target || i == nums.size())
            return;

        ans.push_back(nums[i]) ;
        sumtwo(nums,res,target,n,i+1,sum+nums[i]) ;
        sum = sum-nums[i] ;
        ans.pop_back();
         while (i + 1 < nums.size() && nums[i] == nums[i + 1])
            i++;
        
        sumtwo(nums,res,target,n,i+1,sum+nums[i]) ;
        
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res  ;
        sort(candidates.begin(),candidates.end());
        sumtwo(candidates,res,target,candidates.size()-1,0,0);
        return res ;
    }
};