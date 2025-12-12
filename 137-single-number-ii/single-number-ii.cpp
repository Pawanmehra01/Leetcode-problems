class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>nm;
      for (auto num:nums){
        nm[num]++;
      }
      for(auto x :nm){
        if(x.second == 1)return x.first;
      }
    return -1 ;
    }
};