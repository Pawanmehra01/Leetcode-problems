class Solution {
public:
    int n , m ;
    int dp[301][301] ;
    int res(vector<vector<int>>&matrix , int i , int j){
        if(i >= n || j >= m  ){
           return  0 ;
        }
        if(dp[i][j]!= -1) return dp[i][j] ;
        int right = res(matrix ,i,j+1) ;
        int diagonal = res(matrix , i+1,j+1) ;
        int down = res(matrix, i+1,j) ;
        
        if(matrix[i][j]==1){
             return dp[i][j] = 1+min({right,down,diagonal});
        }
        return dp[i][j] = 0;
 
    }
    int countSquares(vector<vector<int>>& matrix) {
    n = matrix.size();
    m  = matrix[0].size();
    memset(dp,-1,sizeof(dp));
    
    int total =0 ;
    for(int i = 0 ;i <n ;i ++){
        for(int j =0 ;j <m ; j++){
            total+=res(matrix,i,j);
        }
    }
    return total ;
      
    }
};