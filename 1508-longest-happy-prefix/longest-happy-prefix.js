/**
 * @param {string} s
 * @return {string}
 */
var longestPrefix = function(s) {
    const n = s.length;
    const lps = new Array(n).fill(0);

    let i = 1 ;
    let length = 0 ;
   
    while(i<n){

        if(s[i] === s[length]){
            length ++ ;
            lps[i] = length;
            i++;
        }else{
            if(length!==0){
                length = lps[length-1];
            }else{
                lps[i]= 0;
                i++;
            }
        }
       
    }
    
        let start = n - lps[n-1];

        return s.substring(start);

};