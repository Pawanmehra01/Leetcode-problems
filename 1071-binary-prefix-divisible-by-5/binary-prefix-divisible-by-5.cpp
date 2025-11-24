class Solution {
public:
    long long mod = 1e9+7;
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool>ans ;
        long long prev = nums [0] ;
        if(prev%5 == 0)ans.push_back(true);
        else ans.push_back(false);
    
        long long formula ;
        for(int i = 1 ; i < n; i++){
           
            formula =( prev*2 +nums[i] )% 5;
           ans.push_back( formula == 0) ;
           prev = formula;

        }
        return ans;
    }
};