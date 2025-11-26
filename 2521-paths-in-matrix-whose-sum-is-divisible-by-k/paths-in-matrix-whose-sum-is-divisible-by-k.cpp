class Solution {
public:
    int mod = 1e9 + 7;
    int solve(vector<vector<int>>&grid , int k  , int i ,int j ,int sum, vector<vector<vector<int>>>&dp){
        if( i >grid.size()-1 || j >grid[0].size()-1 || i< 0||j<0){

            return 0 ;
        }
        if(dp[i][j][sum]!=-1){
            return dp[i][j][sum]; 
        }
        if(i == grid.size()-1 && j == grid[0].size()-1 ){
           if((sum + grid[i][j])%k == 0) return 1 ;
           else return 0 ;
        }
        int right = solve(grid ,k , i+1 , j ,(sum+grid[i][j])%k,dp);
        int down  = solve(grid , k ,i , j+1 ,(sum+grid[i][j])%k,dp);
        return dp[i][j][sum] = (right%mod+ down%mod )%mod;

    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        
    //creating dp as it contains  3D dp ;
   //containing  i*j*51( sum%k )
  vector<vector<vector<int>>>dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(51,-1)));
    return solve(grid , k ,0 , 0 , 0,dp) ;//grid,k ,i , j ,sum 

    }
};