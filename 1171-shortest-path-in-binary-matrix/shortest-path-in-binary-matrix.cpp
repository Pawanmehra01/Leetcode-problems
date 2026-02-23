class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1)return -1 ;
        int n = grid.size() ;
        vector<vector<bool>>visited(n , vector<bool>(n ,false)) ;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>que;
        int steps = 1 ;
        que.push({steps,{0 ,0 }});
        while(!que.empty()){
            auto it  = que.top() ;
            int i =  it.second.first ;
            int j = it.second.second ;
            int distance = it.first ;
            if(i ==n-1 && j==n-1) return distance;
            que.pop();
            int dx[8] ={-1, -1, -1, 0, 0, 1, 1, 1};
            int dy[8] ={-1, 0, 1, -1, 1, -1, 0, 1};
            for(int k = 0 ;k < 8 ; k ++ ){
                int newrow = i + dx[k] ;
                int newcol = j + dy[k] ;
                if(newrow>=0 && newcol>=0 && newrow<n && newcol<n && grid[newrow][newcol] == 0 && !visited[newrow][newcol] ){
                   visited[newrow][newcol] = true ;
                   
                   que.push({distance+1 ,{newrow,newcol}});
                   
                }
            }

        }
        return -1;
    }
};