class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& isWater) {
           int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>>result(n,vector<int>(m,-1));//visited
        queue<pair<int,int>>que;
            for(int i = 0 ;i< n ;i ++){
                for(int j = 0 ;j < m ; j ++){
                    if(isWater[i][j] == 0) {
                        result[i][j] = 0 ; 
                        que.push({i,j});
                    }
                }
            }
        int dx[4] = {0,+1,0,-1};
        int dy[4] = {+1,0,-1,0};
        while(!que.empty()){
            int  row = que.front().first ;
            int  col = que.front().second ;
            que.pop();
            for(int  i = 0 ;i < 4 ;i++){
                int newrow = row + dx[i] ;
                int newcol = col + dy[i] ;
                if(newrow>=0 && newcol>=0 && newrow<n && newcol<m && result[newrow][newcol]==-1){
                    result[newrow][newcol] = 1 +result[row][col] ;
                    que.push({newrow,newcol});
                }
            }
        }


        return result; 
    }
};