class Solution {
public:
    
    // void bfs(vector<vector<int>>& grid, vector<vector<bool>>&visited,int x , int y ){
    //         visited[x][y] = true ;
    //         int n = grid.size() ;
    //         int m = grid[0].size() ;
           
    //         que.push({minutes ,make_pair(x,y)}) ;
            
    // }
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size() ,false)) ;
        int minutes = 0 ;
       queue<pair<int,pair<int,int>>>que ;
        int n = grid.size();
        int m  = grid[0].size() ;
      
        for(int i = 0 ; i< n ; i ++ ){
            for( int j = 0 ; j< m ;j ++){
                if(!visited[i][j] && grid [i][j] == 2 ){
                que.push({minutes,{i , j }});
                visited[i][j] = true ;    }
            }
        }
        
            int dy[4] = {+1 , 0  ,-1 , 0} ;
            int dx[4] = {0 , +1, 0 ,  -1} ;
            while(!que.empty()){
                int row = que.front().second.first ;
                int col  = que.front().second.second ;
                int time = que.front().first ; 
                minutes = max(time , minutes) ;
                que.pop();
                for(int i = 0 ;i < 4 ;i ++){
                    int newrow = row + dx[i] ;
                    int newcol = col + dy[i] ;
                    if(newrow < n &&  newcol < m && newrow >= 0 && newcol >=0  
                       && grid[newrow][newcol]==1 ){
                        if(!visited[newrow][newcol]){
                        visited[newrow][newcol] = true ;
                        que.push({time+1 ,{newrow,newcol}});
                        }   
                    }
                }
            }
            cout<<minutes ;
        for(int i = 0 ; i < n ;i ++ ){
            for( int j = 0 ;j < m ; j++){
                if(!visited[i][j]  && grid[i][j] == 1){
                 minutes = -1  ;
                }
            }
        }return minutes ;
        
    }
};