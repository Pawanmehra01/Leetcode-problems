class Solution {
public:
    int n ;
    int m ;
    int dp[501][501][3];
    int solve(vector<vector<int>>& coins , int i , int j,int neut ){
        if(i>n-1 || j > m-1)return INT_MIN  ; 
        if(i==n-1 && j == m-1){
            if(coins[i][j]<0 && neut >0)return 0 ;
            else return coins[i][j] ;
        }
        if(dp[i][j][neut]!= INT_MIN)return dp[i][j][neut] ;
        int take = coins[i][j] + max(solve(coins,i,j+1,neut),solve(coins,i+1,j,neut));
        int not_take = INT_MIN ;
        if(coins[i][j]<0 && neut >0)
        not_take = max(solve(coins,i,j+1,neut-1),solve(coins,i+1,j,neut-1));
      
        return dp[i][j][neut] = max(take,not_take) ;
    }
    int maximumAmount(vector<vector<int>>& coins) {
        n = coins.size() ;
        m = coins[0].size();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                for(int k = 0; k < 3; k++)
                    dp[i][j][k] = INT_MIN;
                    
        return solve(coins, 0 , 0 ,2);
    }
};