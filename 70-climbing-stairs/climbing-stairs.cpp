class Solution {
public:

    int steps(int n , vector<int>&dp){
        if(n==0)return 1 ;
        if(n==1)return 1 ;
        if(dp[n]!= -1){
            return dp[n];
        }

        dp[n] = steps(n-1,dp)+steps(n-2,dp) ;
        return dp[n];
       
       
       
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return steps(n,dp);
    }
};