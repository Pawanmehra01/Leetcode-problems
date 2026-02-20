class Solution {
public: 
    int INF =1e9+7;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int, int>>>adj ;//vector<pair<int,int>>adj[n] ;
        for(int i = 0 ;i < flights.size() ; i++ ){
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            adj[u].push_back({v,w});
        }
        queue<pair<int,pair<int,int>>>que ;
        int stops =  0 ;
        vector<int>dist(n ,INF) ;
        int distan  = 0 ;

        que.push({stops, {src, distan }});
        while(!que.empty()){
            auto top  = que.front() ;
            int stops = top.first ;
            int Node  = top.second.first ;
            int distance = top.second.second ;
            que.pop() ;

            if(stops > k )continue ;

            for(auto  i : adj[Node]){
                int nextNode = i.first ;
                int nextnodeweight = i.second ;
                if(distance + nextnodeweight  < dist[nextNode]){
                    dist[nextNode] = distance + nextnodeweight ;
                    que.push({stops+1, {nextNode,dist[nextNode]}});
                }
            }

        }
        if(dist[dst] == INF)return -1 ;
        else return dist[dst] ;


    }
};