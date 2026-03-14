class Solution {
public:
    int low = 0 ;
    int findMin(vector<int>& arr) {
        int n  = arr.size() ;
       
        int high  = n-1 ;
        while(low<high){
            int mid = low + (high-low)/2 ;
           if( arr[mid] > arr[n-1] )low = mid+1 ;
           else high = mid ;
        }
       
        return arr[low];
    }
};