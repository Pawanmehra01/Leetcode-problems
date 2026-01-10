class Solution {
public:
    
    int n , m ;
    // vector<int<int>>dp;
    int dp[1001][1001];
    int solve(string &s1 , int i  , string &s2 , int j ){
        if(i==n && j==m ) return 0 ;
        if(i==n)return int(s2[j]) +solve(s1,i,s2,j+1 );
        if(j==m)return int(s1[i]) +solve(s1,i+1,s2,j );

        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i] == s2[j]){  
         return dp[i][j]=solve(s1,i+1,s2,j+1 );
        }

        int c1 = int(s1[i]);
        int c2 = int(s2[j]);
        int sum = c1+ solve(s1,i+1,s2,j);
        int res = c2 +solve(s1,i,s2,j+1);
        return dp[i][j] = min(sum,res);
        
    }
    int minimumDeleteSum(string s1, string s2) {
        n  = s1.length() ;
        m  = s2.length();
        memset(dp,-1,sizeof(dp));
        return solve(s1,0,s2,0);
    }
};