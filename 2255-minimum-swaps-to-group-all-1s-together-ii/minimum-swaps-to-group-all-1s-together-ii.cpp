class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int i = 0 ;
        int j = 0 ;
        int n = nums.size() ;
        int Ones = accumulate(begin(nums),end(nums),0) ;
        //classic sliding window template 
        // now with space optimization
        int count_ones = 0 ;
        int min_zero_window  = 0 ;
        while(j<2*n){
          if(nums[j%n]){
            count_ones++ ;
          }
          if(j-i+1 > Ones){
            count_ones -= nums[i%n];
            i++;
          }
        min_zero_window = max(min_zero_window,count_ones) ;
        j++ ;

        }
        return   Ones - min_zero_window;
      }
    };