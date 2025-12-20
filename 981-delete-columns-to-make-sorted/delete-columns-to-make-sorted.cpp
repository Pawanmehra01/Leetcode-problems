class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int count = 0 ;
        for(int i = 0 ;i < m;i ++){
            char ch = strs[0][i] ;
            for(int j = 1 ;j < n; j++){
                if(strs[j][i] >=ch){
                    ch=strs[j][i];
                }
                else {
                    count++ ;
                    break;
                }
            }
        }
        return count ;
    }
};