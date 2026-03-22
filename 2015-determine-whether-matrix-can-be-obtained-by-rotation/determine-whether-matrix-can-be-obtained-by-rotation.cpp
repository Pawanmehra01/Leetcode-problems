class Solution {
public:
    void check(vector<vector<int>>& mat){
        int n  = mat.size() ;
        for(int i = 0 ;i < n ;i ++ ){
            for( int j = i ;j < n ;j ++)
            swap(mat[i][j],mat[j][i]);
        }
        for( int i = 0 ;i < n ;i ++ ){
            reverse(mat[i].begin(),mat[i].end());
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();

        for(int rotate = 0 ;rotate < 4  ;rotate ++){
             
            bool not_equal = false;
            for(int i = 0 ;i < n ;i ++ ){

                for(int j = 0 ;j < n;j ++){
                    
                    if(mat[i][j] != target[i][j]){
                        not_equal = true;
                        break;
                    }
                }
                if(not_equal)break;
            }
            if(not_equal)check(mat);
            else return true;

        }
        return false;

    }
};