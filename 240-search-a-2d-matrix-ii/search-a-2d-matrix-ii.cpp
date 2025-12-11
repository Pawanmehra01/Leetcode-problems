class Solution {
public: 
    bool binarysearch(vector<vector<int>>&matrix , int target ,int i ){
        int low  = 0 ;
        int high = matrix.size()-1;
        while(low<=high){
            int mid = (low)+(high-low)/2 ;
            if(matrix[mid][i] == target)return true ;
            else if (matrix[mid][i] >target)high=mid-1 ;
            else if(matrix[mid][i]<target)low = mid+1 ;
        }
      return false ;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n  = matrix[0].size();
    int m = matrix.size() ;
        for( int i = 0 ;i < n ; i ++ ){
             //calll for binary saerch for elemebnt in n col;
           if( binarysearch(matrix,target,i))return true;
        }
    return false ;
    }
};