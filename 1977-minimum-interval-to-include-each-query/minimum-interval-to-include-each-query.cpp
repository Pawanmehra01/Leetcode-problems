class Solution {
public:
    typedef pair<int,int>P ;
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // int n = queries.size()  ;
        // int x = intervals.size() ;
        // int mn = INT_MAX;  ;
        // vector<int>ans ;
        // for( int  i=0 ;i < n  ;i ++){
        //     int q = queries[i] ;
        //     for( int i = 0 ;i < x; i ++ ) { 
        //        int a  = intervals[i][0] ;
        //        int b  = intervals[i][1] ;
        //        if(q>=a && q<=b){
        //         mn = min(mn ,b-a+1) ;
        //        }
               
        //     }
        //     ans.push_back(mn) ;
        //     mn=INT_MAX;
        // } for( int  i= 0 ;i < ans.size();i++){
        //     if(ans[i]==INT_MAX)ans[i] =-1 ;
        // }
        // return ans ;
        //got tle ;starightforward brute force  tc: - O(n*m)

        //  minheap solution
        int n = intervals.size();
        int x = queries.size();
        sort(intervals.begin(),intervals.end());
        vector<P>arr ;
        for( int i = 0 ;i < x ; i ++ ) {
            arr.push_back({queries[i],i});
        }
        sort(arr.begin(),arr.end());

        vector<int>ans(queries.size(),-1);
        priority_queue<P,vector<P>,greater<P>>minhp ;
        int i = 0 ;

        for(auto &interval : arr){
            int query = interval.first ;
            int index = interval.second ;
                while(i<n&& query >= intervals[i][0]){
                    int r  = intervals[i][1];
                    int l =  intervals[i][0] ;
                    minhp.push({r - l + 1 , r });
                    i++;
                }
                while(!minhp.empty() && minhp.top().second < query){
                    minhp.pop();
                }
                if(!minhp.empty()){
                    ans[index] = minhp.top().first ;
                }

        }

         
       return ans ;
    }
};