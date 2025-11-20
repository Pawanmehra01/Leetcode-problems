class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n = intervals.size() ;
        auto lamda = [] (auto &a ,auto &b){
            //if r not equal then sort ont the basis of r otherwise on the of l//
            if(a[1]!=b[1])return a[1]<b[1];
            return a[0]>b[0] ;
        };
        sort(intervals.begin(),intervals.end(),lamda) ;
        int result = 0 ;
        int first  = -1;
        int second = -1 ;
        //rather then using set we are simply adding the count , we dont have to use set and increase the space complexity 
        for( int i = 0 ; i < n ;i++){
            int l = intervals[i][0];
            int r = intervals[i][1];

            if(l<=first)continue ;

            if(l>second){
            first = r-1;
            second = r ;
            result += 2 ;
            }else{
                first = second  ;
                second = r ; 
                result += 1 ;

            }

        }
        return result ;
    }
};