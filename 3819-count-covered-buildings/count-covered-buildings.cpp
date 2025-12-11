class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int,pair<int,int>>yTominmaxX;
        unordered_map<int,pair<int,int>>xTominmaxY;

        for(auto building :buildings){
            int x = building[0];
            int y = building[1];

            if(!yTominmaxX.count(y)){
                yTominmaxX[y] = {INT_MAX,INT_MIN};
            }
            if(!xTominmaxY.count(x)){
                xTominmaxY[x] = {INT_MAX,INT_MIN};
            }
            yTominmaxX[y].first = min(yTominmaxX[y].first,x);
            yTominmaxX[y].second = max(yTominmaxX[y].second,x);

            xTominmaxY[x].first = min(xTominmaxY[x].first,y);
            xTominmaxY[x].second = max(xTominmaxY[x].second,y);

        }
        int result  = 0 ;
        for( auto building : buildings){
            int x =building[0];
            int y = building[1];

            auto &xr = yTominmaxX[y];
            auto &yr = xTominmaxY[x];

            if(xr.first < x && x <xr.second && yr.first<y && y <yr.second){
                result = result +  1 ;
            }
        }
        return result ;

    }
};