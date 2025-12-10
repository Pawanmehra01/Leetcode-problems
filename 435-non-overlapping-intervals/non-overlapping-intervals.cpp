class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
int n = intervals.size();
int count = 0 ;

      
        int two = intervals[0][1];
        for(int i = 1 ;i < n ; i ++){
          int the = intervals[i][0];
          int four = intervals[i][1];
          if(two > the ){
            
            count ++;
            two = min(two , four);
            continue;

          }
          else{
              two = four ;
          }
        }
        return count ;

    }
};