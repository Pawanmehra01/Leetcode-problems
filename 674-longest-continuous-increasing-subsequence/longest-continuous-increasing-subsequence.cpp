class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
    //     stack<int>st ;
    //     int count = 0 ;
    //     int mx = 0 ;
    //     for( int i = 0 ;i< nums.size();i++){
    //         while(!st.empty()&&st.top()>nums[i]){
    //         st.pop();
    //         count = 0 ;
    //         }if(!st.empty()&&st.top()==nums[i]){
    //             continue ;
    //         }
    //         st.push(nums[i]) ;
    //         count++ ;
    //         mx = max(count , mx);
    //    }
    //    return mx ;'
     int count = 1 ;
     int mx = 1 ;
      for( int i = 1 ;i< nums.size() ;i++){
            if((nums[i-1]<nums[i]))count++ ;
            
            else count = 1 ;

            mx = max (mx,count) ;
      }
      return mx ;
    }
};