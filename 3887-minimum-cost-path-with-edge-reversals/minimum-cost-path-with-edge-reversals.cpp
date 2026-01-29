class Solution {
public:
    int INF = 1e9 ;
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int,int>>>mp ;
        for(int i = 0 ;i < edges.size() ;i ++ ){
            int u  = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            mp[u].push_back({v,w});
            mp[v].push_back({u,2*w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n,INF);
        int source = 0 ;
        dist[source] = 0 ;
        //weight followed by node
        pq.push({0,source});
        while(!pq.empty()){
            int weight  = pq.top().first ;
            int Node = pq.top().second ;

            pq.pop();
  
            //for stale Nodes
            if(weight > dist[Node])continue;//stale value 

            for(auto node : mp[Node]){
                if(weight + node.second < dist[node.first]){
                    dist[node.first] = weight + node.second;
                    pq.push({dist[node.first],node.first});
                }
            }
        }
        if(dist[n-1]==INF)return -1;
        return dist[n-1];
    }
};