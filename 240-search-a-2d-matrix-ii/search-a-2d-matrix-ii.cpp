class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       if(matrix.size()==1 && matrix[0][0] == target )return true ;
      
        int m = matrix[0].size()-1;
        int n = matrix.size()-1;
        int top = 0 ;
        int right = m ;
        while (top <=n &&  right>=0 ){
            if(matrix[top][right] ==  target)return true ;
            else if( matrix[top][right]>target)right-- ;
            else top++ ;
        }
        return false ;

    }
};