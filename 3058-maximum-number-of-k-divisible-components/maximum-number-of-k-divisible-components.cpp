class Solution {
public:
    int dfs(int node , int parent ,unordered_map<int,list<int>>&graph ,
            vector<int>&values , int k ,int &CompCount ){
                int sum  = 0 ;
                for( auto neighbours :  graph[node]){
                    if(parent != neighbours){
                        sum +=  dfs(neighbours,node,graph ,values, k ,CompCount) ;
                         sum = sum% k ;
                    }
                }
                sum =sum+values[node] ;
                sum =sum% k; 
                if(sum==0){
                    CompCount++ ;
                }
                return sum ;
            }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        unordered_map<int,list<int>>graph ;
        for(int i = 0 ;i < edges.size() ;i ++){
            int u  = edges[i][0] ;
            int v  = edges[i][1] ;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int CompCount = 0 ;
        int node =  0 ;
        int parent =  -1 ;
        dfs(node, parent,graph ,values, k ,CompCount) ;
        return CompCount ;

    }
};