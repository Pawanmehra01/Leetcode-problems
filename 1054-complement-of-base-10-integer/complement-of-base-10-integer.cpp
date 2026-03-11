class Solution {
public:
    int bitwiseComplement(int n) {
      
        // int number = 1 ;
        // while(number<n){
        //     number = (number<<1 )|1 ;
        // }
        // return number ^ n ;
        if(n==0)return 1 ;// value of log 0 will be  towards - infinity or undefined
        
        int bits = floor(log2(n))+1;//this technique is used to find the number of bits 
        int mask = (1 << bits )- 1; 
        return n^mask;

       
    }
};