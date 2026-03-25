class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        long long pre  = 0;
        for(int i = 0 ;i < n ;i ++ ){
            for(int j = 0 ;j < m ; j ++ ){
                pre = pre + grid[i][j] ;
            }
        }
        if(pre % 2 != 0 )return false ;
        long long check = pre / 2;
        long long prefix1 = 0 ; 
        for(int i = 0 ;i < n ;i ++ ){
    
            for(int j = 0 ;j < m ; j ++ ){
                prefix1 = prefix1 + grid[i][j] ;

            } 
            long long totalsum = pre - prefix1 ;
            if(totalsum == check) return true ;
        }

        long long  prefix2  = 0;
        for(int i = 0 ;i < m ;i ++ ){
           
            for(int j = 0 ;j < n ; j ++ ){
                prefix2 = prefix2 + grid[j][i] ;   
            }
            long long totalsum = pre - prefix2 ;
            if(totalsum == check) return true ;
        }
        return false;
    }
};