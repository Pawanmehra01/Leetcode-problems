class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int,list<int>>adj ;
        int n = graph.size() ;
        //here i reverse the graph
        for(int i = 0 ;i < n ;i ++ ){
            int length =  graph[i].size() ;
            for(int j = 0; j< length;j++){
                int node = graph[i][j];
                adj[node].push_back(i);
            }
        }
        vector<int>indegree(graph.size(),0 ) ;
        for(auto i : adj){
            for(auto j : i.second ){
            indegree[j] ++ ;
            }
        }
        queue<int>que;
        for(int i = 0 ; i<  indegree.size();i++){
            if(indegree[i] == 0 ){
                que.push(i);
            }
        }
        vector<int>result ;
        while(!que.empty()){
            int top  = que.front();
            result.push_back(top) ;
            que.pop();
            for(auto neighbour : adj[top]){
                indegree[neighbour]-- ;
                if(indegree[neighbour] == 0){
                    que.push(neighbour);
                }
            }
        }
        sort(result.begin(),result.end()) ;
        
        return result ;

    }
};