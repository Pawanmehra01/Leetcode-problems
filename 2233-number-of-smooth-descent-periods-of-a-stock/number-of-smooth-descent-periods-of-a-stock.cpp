class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long n = prices.size();
        long long result = 1 ;
        long long count = 1 ;
       
        for( long long i = 1;i < n ;i ++){
            if(prices[i-1]-prices[i] ==  1 ){
              count = count+1 ;
            }else{
              count = 1 ;
            }
            result = result + count;
        }
           
        return result;
        
    }
};