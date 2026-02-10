class Solution {
public:
    int dp[2001][2001];
    int n , m ;
    bool res(string &s , string &p , int i , int j ){
       if (i == n && j == m) return true;

        // pattern finished but string not
        if (j == m) return false;

        // string finished
        if (i == n) {
            // remaining pattern must be all '*'
            while (j < m && p[j] == '*') j++;
            return j == m;
        }
        if(dp[i][j]!=-1)return dp[i][j];

        
        if(s[i] == p[j] || (p[j]=='?')){
           return dp[i][j] = res(s,p,i+1,j+1);
        }
        if(p[j]=='*'){
           return dp[i][j] = res(s,p,i+1,j)||res(s,p,i,j+1);
        }
      
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        
        int i = 0 ;
        int j = 0 ; 
        n = s.length();
        m = p.length() ;
        memset(dp,-1,sizeof(dp));
        
        return res(s, p , i , j);
    }
};