class Solution {
public:
    bool areSimilar(vector<vector<int>>& grid, int k) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        k=k%m;
        vector<vector<int>>copy(n,vector<int>(m)) ;
        for(int i = 0 ;i < n ;i ++ ){
            for(int j = 0 ;j < m ;j ++ ){
                if(i%2 == 0){
                   copy[i][(k+j)%m] = grid[i][j] ;
                }else{
                   copy[i][(j-k+m)%m] = grid[i][j] ;
                }

            }
        }
        for(int i = 0 ;i < n ;i ++ ){
            for(int j = 0 ;j < m ;j ++ ){
                cout<<copy[i][j];


            }cout<<endl;
        }
        
        for(int i = 0 ;i < n ;i ++ ){
            for( int j = 0 ; j<m ;j++){
               if(copy[i][j]!=grid[i][j])return false;
            }
        }

        return true ;

    }
};