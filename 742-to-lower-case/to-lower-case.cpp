class Solution {
public:
    string toLowerCase(string s) {
        string res = "";
        for(int i = 0 ;i < s.length() ;i ++){
           char ch = s[i];

           if(ch>=65 && ch<=90){
            res += ch+32;
           }else{
            res+=s[i];
           }
        }
        return res; 
    }
};