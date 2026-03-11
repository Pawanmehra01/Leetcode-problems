class Solution {
public:
    int bitwiseComplement(int n) {
      
        int number = 1 ;
        while(number<n){
            number = (number<<1 )|1 ;
        }
        return number ^ n ;
       
    }
};