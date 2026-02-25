class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>ans ;
        int n = arr.size() ;
        for(int i = 0 ;i < n ;i ++){
            int x = arr[i] ;
            int count = 0 ;
            
           while(x != 0){
            int result= x & 1;
            if(result)count++ ;
            x = x >> 1;
           }
           ans.push_back({count,arr[i]});
        }
        sort(ans.begin(),ans.end()) ;
        vector<int>res;
        for(auto i : ans){
           res.push_back(i.second);
        }
        return res ;
    }
};