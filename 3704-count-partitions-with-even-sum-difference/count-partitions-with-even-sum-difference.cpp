class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n);
        int sum = 0 ;
        int count = 0;
        for( int i = 0 ;i < n ; i ++ ){
            prefix[i] = sum +nums[i] ;
            sum = prefix[i] ;
        }
       
        int ans  = 0;
        int i =1;
        while(i<=n-1){
            int ans = prefix[i] ;
            int sol = prefix[n-1] - prefix[i];
            if(abs((ans-sol))%2==0 )count++ ;
            cout << "sum diff"<<ans-sol<<endl;
            cout<<"count"<<count<<endl;
            i++ ;
        }if(count == 0)return 0 ;
        return count ;
    }
};