class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
         unordered_map<int,int>mp;
         for( auto num : nums){
            mp[num]++;
         }
         vector<int>res ;
         int n = nums.size() ;
         int val = (n/3);
         for( auto &p : mp){
           if( p.second  > val){
              res.push_back(p.first);
           }
         }
         return res;
         
    }
};