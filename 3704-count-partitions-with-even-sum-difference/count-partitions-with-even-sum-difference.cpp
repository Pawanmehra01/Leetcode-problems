class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n);
        int sum = 0 ;
        int count =0 ;
        for( int i = 0 ;i < n ; i ++ ){
            prefix[i] = sum +nums[i] ;
            sum = prefix[i] ;
        }
        if(prefix[n-1]%2 != 0)return  0 ;
        int ans  = 0;
        int i =0 ;
        while(i<n){
            int ans = prefix[i] ;
            int sol = abs(prefix[n-1] - prefix[i]) ;
            if((ans+sol)%2==0 )count++ ;
            i++ ;
        }
        return count-1;
    }
};