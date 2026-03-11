class Solution {
public: 
    int M = 1e9+7 ;
    int dp[201][201][2] ;
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp,0,sizeof(dp));
        dp[0][0][1] = 1 ;
        dp[0][0][0] = 1 ;
        
        for(int i = 0 ;i <=one ; i++ ){
            for(int j = 0 ; j <=zero ;j ++ ){
                    if(i == 0 && j == 0)continue ;
                        int result = 0 ;
                        for(int k = 1 ;k <= min(limit,j); k++){
                           result = (result + dp[i][j-k][0])%M;
                        }
                        dp[i][j][1] = result;
                    
                        result = 0;
                        for(int k = 1 ;k <= min(limit,i); k++){
                            result  = (result + dp[i-k][j][1])%M;
                        }
                        dp[i][j][0] = result ;
                }
                    
            }
        
        return (dp[one][zero][0] + dp[one][zero][1]) % M;
    }
};