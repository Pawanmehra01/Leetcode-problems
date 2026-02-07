class Solution {
public:

int dp[1001][1001] ;

int solve( string &s ,string &ans , int  m , int n ){
        if( m== 0 || n==0)return 0;
        if(dp[m][n]!=-1){
            return dp[m][n] ;
        }
        int ans2  = 0 ;
        if(s[m-1]==ans[n-1]){
          
           ans2  =  1+solve(s,ans,m-1,n-1);
        }
        int  One =  max(solve(s, ans,m-1,n) , solve(s,ans,m,n-1) ); 
        return dp[m][n] = max(One,ans2) ;
       
        
    }

    int minInsertions(string s) {
       string ans  = s ;
        reverse(ans.begin(),ans.end()) ;
        int m = s.length();
        int n = ans.length() ;
        memset(dp,-1 ,sizeof(dp));
        int res = solve(s,ans, m , n );
        if(res==0)return 0 ;
        return m-res; 
    }
};