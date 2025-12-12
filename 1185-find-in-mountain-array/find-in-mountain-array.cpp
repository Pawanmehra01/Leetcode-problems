/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n  = mountainArr.length();
        int i = 0 ;
        int j = n-1 ;
        while(i< j){
            int mid = i+(j-i)/2 ;
            if(mountainArr.get(mid)>mountainArr.get(mid+1)){
                j = mid;

            }else {
                i = mid+1;
            }
        }
        int peak = i ;
       
      
        int mn = -1;
        int low  =  0 ;
        int high  = peak;
        bool ans = false ;
        bool flag = false ;
        //first half is increasing

        while(low<=high){
            int mid = low+(high - low )/2 ;
            int element = mountainArr.get(mid);
                if(element==target){
                   mn=mid;
                   ans = true ;
                   break;
                   
                }else if(element>target){
                    high = mid-1 ;

                }else{
                    low = mid+1 ;
                }
        }
        if(ans)return mn ;


        //second half is deacreaasing
        int start  = peak ;
        int last = n-1 ;
            while(start<=last){
            int mid = start+(last- start)/2 ;
            int element  = mountainArr.get(mid) ;
                if(element == target){
                    mn = mid ;
                    break;
                  
                }else if (element>target){
                    start=mid+1 ;

                }else{
                    last = mid-1 ;
                }
            }
            
            return mn ;
        }
};