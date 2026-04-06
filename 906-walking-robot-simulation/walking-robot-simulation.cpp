class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int n = commands.size();
        set<string>st; 
        for(vector<int>&obs : obstacles){
            int x = obs[0] ;
            int y = obs[1] ;
            string key = to_string(x) +"_"+ to_string(y);
            st.insert(key);
        }
        int x = 0 ;
        int y = 0 ;
        int ED = 0 ;
        pair<int,int>dir = {0 ,1} ; // as it start from north direction
         
        for(int i = 0 ;i < n ;i ++){

            if(commands[i] == -1){
                dir ={dir.second,-dir.first};
               
            }else if(commands[i] == -2){
                dir ={-dir.second, dir.first} ;
            }else{
                for(int j = 0 ;j <commands[i] ;j++){
                    int newX = x + dir.first ;
                    int newY = y + dir.second;

                    string key = to_string(newX) + "_" +to_string(newY);
                    if(st.find(key)!=st.end()){
                        break;
                    }
                    x = newX ;
                    y = newY ;
                }

            }
            ED = max(ED ,(x*x)+ (y*y));

        }
        return ED;
        
    }
};