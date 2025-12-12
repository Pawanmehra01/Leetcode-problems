class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>ans;
         int n = nums.size();
        unordered_map<int,int>nm;
      for (auto num:nums){
        nm[num]++;
      }
      for(auto x :nm){
        if(x.second == 1)ans.push_back(x.first);
      }
    if(ans.size()==0)return {};
    else return ans;
    }
};