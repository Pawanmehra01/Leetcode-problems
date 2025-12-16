class Solution {
public:
 vector<int>ans ;
    void solve(vector<vector<int>>&sum , int i , int n  ,vector<int>&nums){
        if(i>n){
            sum.push_back(ans);
            return ;
        }
        ans.push_back(nums[i]);
        solve(sum,i+1, n , nums);
        ans.pop_back();
        while(i+1<nums.size() && nums[i]==nums[i+1])i++;
        
         solve(sum,i+1, n,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         vector<vector<int>>sum ;
         sort(nums.begin(),nums.end());
    vector<int>ans ;
    solve(sum , 0 , nums.size()-1,nums);
    return sum ;
    }
};