class Solution {
public:
    bool checkSorted(vector<int>&nums){
        
        for(int i = 1 ;i < nums.size() ; i ++){
            if(nums[i]<nums[i-1])
            return false ;
        }
        return true;
    }
    int minSum(vector<int>&nums){
        int minum = INT_MAX;
        int index = -1 ;
        for(int i = 1;i < nums.size();i++){
            if(nums[i-1]+nums[i]<minum){
            index = i-1 ;
            minum = nums[i-1]+nums[i];
          }
        }
        return index ;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
       
        bool  ans = checkSorted(nums);
        int operation = 0 ;
        if(ans){
            return 0;
        }else{
            //5231
       
           while(!checkSorted(nums)){
            int index  = minSum(nums);

            nums[index] = nums[index] + nums[index+1];
            nums.erase(begin(nums)+index+1);
            operation++;
           }
           

        }

    return operation;
    }
};