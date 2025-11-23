class Solution {
public:
int dp [40001][3];
int solve(int i ,vector<int>&nums ,int n ,int sum) {
    if(i>=n)return(sum==0)?0:-1000000000;
      
    if(dp[i][sum]!=-1)return dp[i][sum] ;
    
    int take = nums[i] + solve(i+1,nums,n,(sum+nums[i])%3);
    int not_take = solve(i+1,nums,n , sum);
    return dp[i][sum]= max(take ,not_take);
    

}
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size() ;
        int sum = 0 ;
        memset(dp,-1 ,sizeof(dp));
        return solve(0 ,nums,n,sum);
    }
};