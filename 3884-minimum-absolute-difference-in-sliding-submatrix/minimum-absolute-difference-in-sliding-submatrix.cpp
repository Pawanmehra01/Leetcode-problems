class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n  =  grid.size() ;
        int m  = grid[0].size() ;
        vector<vector<int>>result(n-k+1,(vector<int>(m-k+1))) ;
        for(int i = 0 ;i <= n-k ;i ++ ){
            for(int j = 0 ;j <= m-k ;j ++ ){
                set<int>store;
                for(int i_ = i ;i_ <= i+k-1 ;i_++){
                    for(int  j_ = j ;j_<=j+k-1 ;j_++){
                        store.insert(grid[i_][j_]);
                    }
                }
                if(store.size() == 1){
                    result[i][j] = 0 ;
                    continue;
                }
                int absdiff = INT_MAX ;
                auto prev = store.begin();
                auto curr = next(prev) ;
                while(curr != store.end()){
                    absdiff = min(absdiff ,abs(*prev - *curr) );
                    prev = curr ;
                    curr++ ;

                }
                result[i][j] = absdiff ;
            }
        }
        return result ;
        
    }
};