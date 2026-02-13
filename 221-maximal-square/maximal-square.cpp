class Solution {
public:
    int n , m ;
    int mx = 0;
    int dp[301][301] ;
    int res(vector<vector<char>>&matrix , int i , int j ){
        if(i>=n || j>=m) return 0 ;
        if(dp[i][j] != -1)return dp[i][j] ;
        int right = res(matrix ,i,j+1) ;
        int diagonal = res(matrix , i+1,j+1) ;
        int down = res(matrix, i+1,j) ;
        if(matrix[i][j] == '1'){
            dp[i][j] = 1+ min({right,diagonal,down}) ;
            mx = max(dp[i][j],mx) ;
            return dp[i][j] ;
        }return dp[i][j] = 0 ;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int i = 0 ;
        int j = 0 ;
        n =  matrix.size();
        m = matrix[0].size();
        memset(dp,-1,sizeof(dp));
        res(matrix , i , j) ;
        return mx*mx; 
    }
};