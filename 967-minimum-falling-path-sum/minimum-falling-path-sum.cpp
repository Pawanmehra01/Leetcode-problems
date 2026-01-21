class Solution {
public:
   
    vector<vector<int>>dp;
    int findSum(int row , int col , vector<vector<int>>&matrix,
                int rows , int cols){
        if (row == rows - 1) return matrix[row][col];
        
        if (dp[row][col] != INT_MAX) {
            return dp[row][col];
        }

        int rightdiagonal=INT_MAX;
        int leftdiagonal = INT_MAX;
        int down = INT_MAX;
       
        down = findSum(row+1,col,matrix,rows,cols);
   
        if(col+1<cols){
            rightdiagonal= findSum(row+1,col+1,matrix,rows,cols);
        }
        if(col-1>=0){
           leftdiagonal = findSum(row+1,col-1,matrix,rows,cols);
        }
        return dp[row][col]=matrix[row][col]
               + min({down,rightdiagonal,leftdiagonal});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        dp.assign(rows, vector<int>(cols, INT_MAX));

        int sum =INT_MAX;
        for( int i = 0 ;i < cols ;i++){
            sum= min(sum,findSum(0 , i , matrix,rows,cols));
        }
        return sum;
    }
};