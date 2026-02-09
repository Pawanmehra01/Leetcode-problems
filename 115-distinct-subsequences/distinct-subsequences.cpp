class Solution {
public:
    int dp[1000][1000] ;
    int n , m ;
    int res (string &s , string &t , int i , int j ){
        if(i>=n && j>=m)return 1; 
        if(j>=m)return 1 ;
        if(i>=n)return 0 ;
        if(dp[i][j] !=-1)return  dp[i][j] ;
        int take =  0 ;
        if(s[i]==t[j]){
            take = res(s,t,i+1,j+1);
        }
        int not_take= res(s,t,i+1,j);
        return  dp[i][j] = take+not_take;
         
    }
    int numDistinct(string s, string t) {
        int i  = 0; 
        int j = 0 ;
        n = s.length();
        m = t.length();
        memset(dp,-1,sizeof(dp));
        return res(s,t,i,j);
    }
};