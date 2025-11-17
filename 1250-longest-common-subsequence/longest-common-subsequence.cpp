class Solution {
public:
    int dp[1001][1001];
    int solve(string &text1 ,string &text2 , int m , int n ){
        if(m == 0  || n == 0 )return  0 ;
        if(dp[m][n]!=-1){
            return dp[m][n] ;
        }
        int ans = 0 ;
        if(text1[m-1]==text2[n-1]){
            ans = 1 + solve(text1,text2,m-1,n-1);
        }
        int not_take = max(solve(text1,text2 ,m-1,n),solve(text1,text2,m,n-1));
        return dp[m][n]=max(ans,not_take);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        memset(dp,-1,sizeof(dp));
        return solve(text1,text2,m,n);
    }
};