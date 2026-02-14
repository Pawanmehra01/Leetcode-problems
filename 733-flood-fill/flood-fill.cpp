class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m  = image[0].size(); 
        bool visited[n][m]  ;
        memset(visited, false ,sizeof(visited)) ;
        vector<vector<int>>res(image.size(),vector<int>(image[0].size(),0)) ;
        res = image  ;
        queue<pair<int,int>>que ;
        int element = image[sr][sc] ;
        res[sr][sc] = color;
        que.push({sr,sc}) ;
        int dy[4] = {+1 , 0  ,-1 , 0} ;
        int dx[4] = {0 , +1, 0 ,  -1} ;
        while(!que.empty()){
            int row = que.front().first ;
            int col  = que.front().second ;
            que.pop();
            for(int i = 0 ;i < 4 ;i ++ ){
                    int newrow = row + dx[i] ;
                    int newcol = col + dy[i] ;
                    if(newrow < n &&  newcol < m && newrow >= 0 && 
                        newcol >=0 && res[newrow][newcol] == element && !visited[newrow][newcol]){
                                res[newrow][newcol] = color ;
                                visited[newrow][newcol] = true ;
                                que.push({newrow,newcol});
                    }
            }
        }
    return res ;

    }
};