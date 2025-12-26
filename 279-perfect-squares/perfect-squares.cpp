class Solution {
public: 

    int recursion(vector<int>&nums,int sum ,int target , int i,vector<vector<int>>&dp){
        if(i >= nums.size())
          return 1e9;//as the value needs to be smaller not bigger 
          //so whil ecomparingtake in min we will get small number of combinations
        if(sum==target){
            return 0;
        }
        int take  = 1e9 ; 
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        if(target>=sum+nums[i]){
            take = 1+ recursion(nums,sum+nums[i],target,i,dp) ;
        }
        int not_take = recursion(nums,sum,target,i+1,dp);
        return dp[i][sum] = min(take,not_take);
    }
    int numSquares(int n) {
        vector<int>nums;
        for(int i = 1 ;i<=sqrt(n);i++){
           nums.push_back(i*i);
        }
        vector<vector<int>> dp(nums.size(), vector<int>(n + 1, -1));
        int i = 0 ;
        return  recursion(nums,0 ,n , i,dp);

    }
};