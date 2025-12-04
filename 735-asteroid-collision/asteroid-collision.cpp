class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        //+ RIGHT ;
        //- LEFT ;
        //5 10 -5 ;
        int n = asteroids.size();
        vector<int>ans ;
        for( int i =0  ;i< n; i++){
            if(asteroids[i] > 0) ans.push_back(asteroids[i]) ;
            else{
                while(!ans.empty() && ans.back() > 0 && ans.back()<abs(asteroids[i])){
                    ans.pop_back() ;

                }if( ans.empty() || ans.back()<0){
                    ans.push_back(asteroids[i]) ;
                }   
                // if both same 
                else if(ans.back() == abs(asteroids[i])){
                    ans.pop_back() ;
                }

                  

            }
        }
        return ans ;
    }
};                                   