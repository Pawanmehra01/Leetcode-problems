class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int i = 0 ;
        int j = 2 ;
        
        while(j<4){
            if(s1==s2)return true;

            if(s1[i] == s2[i]){
                i++ ;
                j++ ;
            }
            else{
                swap(s1[i],s1[j]);
                i++;
                j++;
            }
        }
       
        if(s1==s2)return true;
        return false;
    }
};