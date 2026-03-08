class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        //canters algorithm
        string res = "" ;
        int n = nums.size() ;
        for(int i = 0 ;i < n ;i ++ ){
            char ch  = nums[i][i] ;
            res+=(ch == '0')?'1':'0';
        }
        return res ;
    }
};