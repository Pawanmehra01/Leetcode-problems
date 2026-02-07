class Solution {
public:
    int dp[1001][1001];
    int res(string &text1 , string &text2, int i , int j ){
        if(i>=text1.length()||j>=text2.length()){
            return 0  ;
        }
        if(dp[i][j] != -1)return dp[i][j];
        int take = 0 ;
        if(text1[i]==text2[j]){
           take = 1 + res(text1,text2,i+1,j+1);
        }
        int dont_take = max(res(text1,text2,i,j+1),res(text1,text2,i+1,j));
        return dp[i][j] =  max(take,dont_take);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int i = 0 ;
        int j = 0 ;
        memset(dp,-1,sizeof(dp)) ;
        return res(text1 , text2, i , j );
    }
};