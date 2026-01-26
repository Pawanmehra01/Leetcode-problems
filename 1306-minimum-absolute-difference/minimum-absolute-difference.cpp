class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
        int mn = INT_MAX;
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i = 0 ;i < n-1 ;i ++){
            int diff ;
            diff = nums[i+1]-nums[i];
            mn = min(mn,diff);
          
        }
        for(int  i = 0 ;i < n-1; i++){
            if(nums[i+1]- nums[i] == mn){
                res.push_back({nums[i],nums[i+1]});
            }
        }
        
    return res ;
    }
};