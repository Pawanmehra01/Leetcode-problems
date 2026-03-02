class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // same as 3 sum 

        sort(nums.begin(),nums.end()) ;
        //apply 3 sum 2 pointer logic hete 
        int n = nums.size() ;

        int result = nums[0] + nums[1] +nums[2] ;
        for(int  i = 0 ; i < n-2 ; i ++){
               
           int left  = i+1 ;
           int right  = n-1 ;
                while(left<right){
                    int sum = nums[i] +nums[left] +nums[right] ;
                 //if(my result is of size 3 then result will 
                 //be returned automaticcally but if not then it will be updated here )
                    if(abs(target - sum ) < abs(target - result))
                    result = sum ;
             
                    if(target  == sum )return target ;
                    else if(sum >target )right-- ;
                    else left++ ;
                }
            }
        return result ;
        
    }
};