class Solution {
public: 
    int dp [301][5001] ;
    int helper(int target , vector<int>&nums , int i , int sum ){
        if(sum==target)return 1 ;
        
       
        if(i==nums.size()|| sum>target)return 0 ;
        
        if (dp[i][sum]!=-1)return dp[i][sum] ;
         // stay at one 
        int take  =  helper(target,nums,i , nums[i]+sum) ;
        //move to next 
        int not_take = helper(target,nums,i+1 , sum) ;

        return dp[i][sum] = take + not_take ;
    }
    int change(int amount, vector<int>& coins) {
        int i  = 0 ;
        int sum = 0 ;
        memset(dp , -1 , sizeof(dp));
        return helper(amount,coins, i, sum) ;
        
    }
};