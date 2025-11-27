class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
     int n = nums.size();
     vector<long long >preSum(n) ;
     preSum[0] = nums[0] ;
     //using kadane algoirthm and prefix sum 
     //tc = o(K*n/k) first loop and second loop as lopp trsverse only less than k 
     // sc = O(n) prefic array 
        for(int i = 1 ;i < n ; i++ ){
            preSum[i] =preSum[i-1] + nums[i] ;
        }
        long long result = LLONG_MIN;
        for( int start = 0 ; start < k ;start++ ){
            long long currSum =  0;
            int i  = start ;
            while(i<n && i+k-1 < n){
                int j  = i+k-1 ;
                long long subSum = preSum[j] - ((i > 0) ? preSum[i-1] : 0) ;
                //kadane algorithm logic 
                currSum = max(subSum,currSum + subSum) ;
                result = max(result , currSum) ;
                i+=k ;
            }
        }
        return result ;
    }
};