class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;

        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        int n  = intervals.size();
        int start_one = intervals[0][0];
        int end_one = intervals[0][1] ;

        for(int i = 1 ;i < n; i++){
            int Start_two = intervals[i][0];
            int End_two = intervals[i][1]; 

            if(end_one >= Start_two){
                start_one  = start_one ;
                end_one = max(end_one, End_two) ;
                continue;
            }
            ans.push_back({start_one,end_one});
            start_one = Start_two ;
            end_one = End_two ;

        }
    ans.push_back({start_one,end_one});
    return ans ;

    }
};