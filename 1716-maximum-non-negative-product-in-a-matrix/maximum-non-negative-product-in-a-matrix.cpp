class Solution {
public: 
        int n  ;
        int m  ;
        int mod = 1e9+7 ;
        typedef long long  ll ; 
        vector<vector<pair<ll,ll>>>t ;
        pair<ll ,ll> solve (int i , int j  ,vector<vector<int>>&grid){
            if(i == n-1 && j == m-1)return {grid[i][j] , grid[i][j]};
            
            ll MaxVal = LLONG_MIN ;
            ll MinVal = LLONG_MAX;
            if(t[i][j] != make_pair(LLONG_MIN, LLONG_MAX))return t[i][j] ;
            if(i+1 <= n-1 ){
                //down
                auto [downMax ,downMin] = solve(i+1 , j ,grid) ;
                MaxVal = max({MaxVal ,downMax*grid[i][j] , downMin*grid[i][j]}) ;

                MinVal = min({MinVal,downMax*grid[i][j] , downMin*grid[i][j]}) ;
                
            }
            if(j+1 <=m-1){
                //right
                auto [rightMax ,rightMin] = solve(i,j+1,grid) ;
                MaxVal = max({MaxVal , grid[i][j]*rightMax , grid[i][j]*rightMin}) ;

                MinVal = min({MinVal ,grid[i][j]*rightMax,grid[i][j]*rightMin}) ;
                
            }
            return t[i][j] = {MaxVal ,MinVal} ;
        }

    int maxProductPath(vector<vector<int>>& grid) {
         n  = grid.size() ;
         m = grid[0].size() ;
         t = vector<vector<pair<ll,ll>>>(n ,vector<pair<ll,ll>>(m,make_pair(LLONG_MIN , LLONG_MAX))) ;
         auto [maxVal ,minVal] = solve(0 , 0 , grid );
         return(maxVal < 0)?-1 :maxVal % 1000000007;
        
    }
};