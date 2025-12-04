class Solution {
public: 
    bool isSafe( vector<string>board, int row , int col){
        //right row 
        int n = board.size();

        for( int i = 0 ; i< n ;i++){
            if(board[i][col] == 'Q')return false;
        }

        //downward 
        for( int i = 0 ;i < n ; i++){
            if(board[row][i] == 'Q')return false;
        }
        //upward left diagonal
        int i = row;
        int j = col;
        while(i>=0 && j>=0){
            if(board[i][j] == 'Q')return false;
            i--; j --;

        }//for upaward right 
        i = row;
        j = col;
        while(i>=0 && j<n){
            if(board[i][j] == 'Q')return false;
            i--; j ++;

        }

        return true;
    }
    void tofindWays( vector<string>board,vector<vector<string>>&ans, int row ){
        int n = board.size();
        if(n == row ){
            vector<string>s;
            for(int  i= 0 ;i < n;i++){
                s.push_back(board[i]);
            }
            ans.push_back(s) ;
            return ;

        }
        for(int j = 0 ;j < n; j ++) {
            if(isSafe(board,row, j)){
                board[row][j]='Q'; 
                tofindWays(board,ans,row+1);
                board[row][j]='.' ;
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>>ans ;
        vector<string>board(n,string(n,'.'));
        
        //function to check the ways of putting queens in board so that no queen collapse
        tofindWays(board,ans,0);
        return ans ;
    }
};