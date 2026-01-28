class Solution {
public: 
    int dp[201][20001];
    int n ;

    bool helper(int TotalSum ,vector<int>&nums,int i , int curSum){
         if(TotalSum==curSum)return true;

        if(i>nums.size()-1)return false ;
        if(dp[i][curSum]!=-1){
            return dp[i][curSum];
        }

        int take = helper(TotalSum-nums[i],nums,i+1,curSum+nums[i]);
        int not_take = helper(TotalSum,nums,i+1,curSum);
        return dp[i][curSum] =take||not_take;
    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int TotalSum = 0 ;
        for(int i = 0 ;i<n ;i++){
            TotalSum +=  nums[i];
        }
        memset(dp,-1,sizeof(dp));
        return helper(TotalSum,nums,0,0);
    }
};