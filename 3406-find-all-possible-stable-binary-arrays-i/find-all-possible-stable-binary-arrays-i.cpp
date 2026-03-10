class Solution {
public: 
    int M = 1e9+7 ;
    int dp[201][201][2] ;
    int solve(int limit , int ones ,int zeroes ,bool lastOne){
        if(ones == 0 && zeroes == 0)return 1 ;

        if(dp[ones][zeroes][lastOne] != -1)return dp[ones][zeroes][lastOne] ;
        int result = 0 ;
        if(lastOne == true){
            for(int i = 1 ;i <= min(limit,zeroes); i++){
                result = (result + solve(limit,ones,zeroes-i,false))%M;
            }
        }
        else {
            for(int i = 1 ;i <= min(limit,ones); i++){
                result = (result + solve(limit,ones-i,zeroes,true))%M;
            }
        }
        return dp[ones][zeroes][lastOne] = result ;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp,-1,sizeof(dp));
        int solvewithOnes = solve(limit,one ,zero,true);
        int solvewithZeroes = solve(limit , one ,zero ,false) ;
        return (solvewithOnes + solvewithZeroes)%M ;
        
    }
};