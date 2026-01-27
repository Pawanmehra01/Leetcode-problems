class Solution {
public:
    int dp[101];
    int helper(int n ,vector<int>&nums,int i ){
        if(i>=n)return 0;
        if(i==n-2)return max(nums[n-1],nums[n-2]);
        if(dp[i]!=-1)return dp[i];
        

        int icol = nums[i]+helper(n,nums,i+2);
        int jcol = 0;
        if (i + 1 < n) {
            jcol = nums[i + 1] + helper(n, nums, i + 3);
        }

        dp[i]= max(icol,jcol);
        return dp[i];

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        //2,1 sum = 3 ;
        //1 ,3 sum = 4; 
        int i = 0;
        memset(dp,-1,sizeof(dp));
      
        return helper(n,nums,i);
        
    }
};