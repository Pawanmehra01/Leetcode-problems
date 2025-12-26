class Solution {
public:
    int dp[1001];
    int helper(vector<int>&nums, int target , int n ){
        if(target < 0)return 0 ;
        if(target == 0)return 1 ;

        if(dp[target]!= -1)return dp[target];

        int ways  = 0 ;
        for(int i = 0 ;i < n ; i ++){
            ways = ways + helper(nums,target-nums[i],n);
        }
        dp[target] = ways ;
        return ways;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return helper(nums, target,nums.size());
    }
};