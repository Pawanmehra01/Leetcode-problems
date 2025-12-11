class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size() ;
        if(nums[nums.size()-1] > nums[0]) {
               return nums[0] ;
            }
            
        int low = 0 ;
        int high = n-1;
        while(low<high){
            int mid = low + (high-low)/2 ;
                if(nums[mid] >= nums[0])low = mid+1;
                    else high = mid ;
                
        }
        return nums[high] ;
    }
};