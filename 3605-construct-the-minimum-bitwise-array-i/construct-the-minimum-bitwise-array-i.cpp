class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>res ;
        for(int i = 0 ; i < n ; i ++){
            bool found = false;
            for(int j = 0;j<nums[i];j++){
                if(( j|(j+1) )== nums[i]){
                    res.push_back(j);
                    found = true;
                    break;
                }
            }
            if(!found){
                res.push_back(-1);
            }
        }
        return res;
    }
};