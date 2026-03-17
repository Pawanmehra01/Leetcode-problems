class Solution {
public:
    bool is_valid_weight(int mid , vector<int>&weights , int days){
        int sum = weights[0] ;
        int count = 1 ;
        for( int i = 1 ;i < weights.size() ; i ++ ){
            sum = sum + weights[i] ;
            if(sum > mid){
                sum  = weights[i] ;
                count++ ;
            }
        }
        return count <= days ;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxElement = *max_element(begin(weights),end(weights)) ;
        int maxpackages = accumulate(begin(weights),end(weights), 0) ;
        int low  = maxElement ;
        int high = maxpackages ;

        int result  = -1 ;

        while(low <= high ){
            int mid = low +(high-low)/2 ;

            if(is_valid_weight(mid , weights ,days )){
                result = mid ;
                high = mid-1 ;
            }
            else{
                low = mid+1 ;
            }
        }
        return result ;
    }
};