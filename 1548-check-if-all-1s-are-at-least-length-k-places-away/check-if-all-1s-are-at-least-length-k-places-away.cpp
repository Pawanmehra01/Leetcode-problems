class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0 ;
        int j = 0 ;
        bool ans = true ;
            while(j<n){
                if(nums[j] == 1){
                    if(ans ==false ){
                        if(j-(i+1)>=k){
                            i=j ;
                            j++ ;
                        }else {
                            return false ;
                        }
                    }else if(ans) {
                        ans= false;
                        i = j ;
                        j++ ;
                    }                                                 
                    
                }else if(nums[j]==0)j++ ;
            }
            return true ;
        }
};