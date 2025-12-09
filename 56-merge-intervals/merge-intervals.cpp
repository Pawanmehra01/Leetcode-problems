class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>res ;
        sort(intervals.begin(),intervals.end());
        int start_one = intervals[0][0];
        int end_one = intervals[0][1] ;
        int n = intervals.size();
        for( int  i=1 ; i< n ;i ++){
            int start_two = intervals[i][0];
            int end_two = intervals[i][1] ;
            if(end_one>=start_two){
                start_one = min(start_one,start_two) ;
                end_one = max(end_one ,end_two) ;
                continue; 
            }
            res.push_back({start_one ,end_one});
            start_one = start_two ;
            end_one = end_two ;

        }
        res.push_back({start_one ,end_one});
        return res ;
    }
};