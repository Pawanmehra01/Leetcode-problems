class Solution {
public:
    int mod =  1e9 +7 ;
    typedef long long ll ;
    int maxProductPath(vector<vector<int>>& grid) {
        int n  = grid.size() ;
        int m = grid[0].size() ;
        vector<vector<pair<ll,ll>>>t(n ,vector<pair<ll,ll>>(m)) ;
        t[0][0] ={grid[0][0],grid[0][0]} ;
        for( int i = 1 ; i < m ;i ++ ){
            t[0][i].first =  t[0][i-1].first * grid[0][i] ;
            t[0][i].second = t[0][i-1].second * grid[0][i] ;
        }
        for( int i = 1 ; i < n ;i ++ ){
            t[i][0].first =  t[i-1][0].first * grid[i][0] ;
            t[i][0].second = t[i-1][0].second * grid[i][0] ;
        }
        for(int i = 1 ;i < n ;i ++ ){
            for( int j = 1 ;j < m ; j ++){
                ll topmax = t[i-1][j].first;
                ll topmin = t[i-1][j].second ;
                ll leftmax = t[i][j-1].first;
                ll leftmin = t[i][j-1].second;

                t[i][j].first  = max({topmax * grid[i][j] , topmin *grid[i][j] ,leftmax* grid[i][j] ,leftmin *grid[i][j]}) ;
                t[i][j].second = min({topmax * grid[i][j] , topmin *grid[i][j] ,leftmax* grid[i][j] ,leftmin *grid[i][j]}); 
            }
        }
        if(t[n-1][m-1].first < 0)return -1 ;
        else return t[n-1][m-1].first % mod ;
    }
};