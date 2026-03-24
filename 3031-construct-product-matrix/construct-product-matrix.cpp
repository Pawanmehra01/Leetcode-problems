class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        int mod  = 12345 ;

        vector<vector<int>>Product_Except_itself(n ,vector<int>(m,1)) ;
        long long suffix =  1 ;
        for(int i = n-1 ; i>=0 ;i --){
            for(int j = m-1 ; j>=0 ;j --){
                Product_Except_itself[i][j] = suffix ;
                suffix = (suffix * grid[i][j])%mod ;
            }
        }
        long long prefix = 1 ;//no array needed can be done using array also

        for(int i = 0 ;i < n ;i ++ ){
            for( int  j= 0 ;j <  m ;j ++ ){
                Product_Except_itself[i][j] = (Product_Except_itself[i][j] * prefix) % mod;
                prefix = (prefix * grid[i][j]) %mod ;
            }

        }
        return Product_Except_itself ;

    }
};