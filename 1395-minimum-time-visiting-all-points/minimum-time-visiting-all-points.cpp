class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        //cheby shev fromula for distance if vertical horizontal and diagonal     
        //distance are allowed

        int n = points.size();
        int res = 0 ;
        for(int i = 0 ;i < n-1 ; i++){
            int X =points[i][0];
            int Y =points[i][1];

            int targetX =points[i+1][0];
            int targetY =points[i+1][1];

            res += max(abs(targetX - X ),abs(targetY - Y));

        }
    return res ;

    }
};