class Solution {
public: 
  int count = 0;
    bool isSafe(int n  ,vector<vector<char>>&mat, int row , int col){
        //middle
        for(int i = 0 ;i < n ;i ++ ){
            if(mat[i][col]== 'Q')return false;
        }
      
        //top right
        int r = row ;
        int c = col; 
        while(c < n && r >= 0){
            if(mat[r][c] == 'Q')return false ;
            r--  ;
            c++ ;
        }
        //top left 
        r = row ;
        c = col ;
        while (c>=0 && r>=0){
            if(mat[r][c] == 'Q')return false ;
            r-- ;
            c-- ;
        }
        return true ;
    }
    void fillQueen(int n ,vector<vector<char>>&mat, int row ,int col){
           mat[row][col] = 'Q' ;
           
           if(row == n-1){
            count++ ;
            mat[row][col] = '.' ;  
            return ;
           }
           for(int j  = 0 ; j < n ; j ++ ){
                    if(isSafe(n,mat,row+1,j)){
                        fillQueen(n,mat,row+1,j);
                    }
                }
            
            mat[row][col]='.';
           
    }
    int totalNQueens(int n) {
        //create a matrix
        vector<vector<char>>mat(n,vector<char>(n,'.'));
        for(int j = 0 ;j < n ;j ++ ){
            if(isSafe(n,mat ,0 ,j)){
                fillQueen(n ,mat, 0 , j );
            }
        }
        return count ;
    }
};