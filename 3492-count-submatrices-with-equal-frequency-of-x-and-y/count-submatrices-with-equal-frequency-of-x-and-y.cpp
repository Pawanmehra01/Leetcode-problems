class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        /*
        X Y .
        Y . .
        */
        vector<vector<int>>X_count(n,vector<int>(m,0)) ; 
        vector<vector<int>>Y_count(n,vector<int>(m,0)) ; 

        int result = 0;
        
        for( int i = 0 ;i < n ;i ++ ){
            for( int j = 0 ;j < m ;j ++ ){
                X_count[i][j] = (grid[i][j]=='X') ; //if x count 1 ;
                Y_count[i][j] = (grid[i][j]=='Y') ; //if y count 1;

                if(i-1>=0){
                   X_count[i][j] += X_count[i-1][j] ;
                   Y_count[i][j] += Y_count[i-1][j] ;
                }
                if(j-1 >= 0){
                   X_count[i][j]  += X_count[i][j-1] ;
                   Y_count[i][j]  += Y_count[i][j-1] ;
                }
                if(i-1>=0 && j-1>=0){
                   X_count[i][j]  -= X_count[i-1][j-1] ;
                   Y_count[i][j]  -= Y_count[i-1][j-1] ;
                }
                if(X_count[i][j] == Y_count[i][j] && X_count[i][j]>0)result++ ;
            }     
        }
        return result ;
    }
};