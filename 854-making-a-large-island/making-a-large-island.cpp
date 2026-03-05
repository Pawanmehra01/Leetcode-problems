class Solution {
public: 
    vector<int>parent;
    vector<int>size  ;

    int findParent(int node ){
        if(parent[node] == node)
            return node ;
        return parent[node] = findParent(parent[node]) ;
        
    }

    void makeset(int n ){
        parent.resize(n*n);
        size.resize(n*n);
        for(int i = 0 ; i< n*n ;i ++ ){
            parent[i] = i ;
            size[i] = 1 ;
        }
    }
    void UnionBysize(int u ,int v){
         u = findParent(u) ;
         v = findParent(v) ;

        if(u==v)return  ;

        if(size[u] <size[v]){
            parent[u] = v ;
            size[v] += size[u] ;
        }else{
            parent[v] = u ;
            size[u] += size[v] ;
        }
        
    }
    int largestIsland(vector<vector<int>>& grid) {
    vector<vector<int>>dir = {{-1,0},{1,0},{0,-1},{0,1}} ;
        int n = grid.size() ;
        makeset(n) ;
        

        for( int i = 0 ;i < n; i ++ ){
            for(int j =0 ;j < n ;j ++ ){
                if(grid[i][j] == 1 ){
                   for(int direc = 0 ;direc < 4 ;direc ++ ){
                    int newrow = dir[direc][0] + i;
                    int newcol = dir[direc][1] + j ;
                        if(newrow >= 0 &&  newcol >= 0 && newrow<n  && newcol<n && grid[newrow][newcol] == 1 ) {
                        int curNode = (i * n) + j  ;
                        int adjNode =  (newrow * n ) + newcol ;
                        UnionBysize(curNode , adjNode) ;
                        }
                   }             
                }
            }
        
    }
    int mx = INT_MIN ;
        for( int i = 0 ;i < n; i ++ ){
            for(int j =0 ;j < n ;j ++ ){ 
            set<int>add_island_id;
                if(grid[i][j] == 1 )continue ;
                    for(int direc = 0 ;direc < 4 ;direc ++){
                    int newrow = dir[direc][0] + i;
                    int newcol = dir[direc][1] + j ;
                        if(newrow >= 0 &&  newcol >= 0 && newrow<n  && newcol<n  && grid[newrow][newcol] == 1 ) {
                        
                        int adjNode =  (newrow * n ) + newcol ;
                        add_island_id.insert(findParent(adjNode));
                        
                        }
                    }  
                    int sizeTotal = 1 ;
                    for(auto it  :add_island_id ) {
                        sizeTotal+= size[it] ;

                    }
                    mx = max(sizeTotal , mx) ;
                }         
            }
        return  mx==INT_MIN ? n*n : mx ;
     }
};