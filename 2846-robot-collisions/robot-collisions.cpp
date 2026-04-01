class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n  =  healths.size();
        vector<int>index(n) ;
        // for(int i =0 ;i < n ;i ++){
        //     index[i] = i ;
        // }
        //or we can use 
        iota(begin(index),end(index),0) ;
        auto lambda = [&](int &i , int &j ){
            return positions[i] < positions[j] ;
        } ;
        sort(begin(index) ,end(index), lambda) ;

        vector<int>result ;
        stack<int>st ;

        for(int &currIdx : index) {
            if(directions[currIdx] == 'R'){
                st.push(currIdx) ;
            }else{
                while(!st.empty() &&  healths[currIdx] > 0){
                    int topIdx = st.top();
                    st.pop();

                    if(healths[topIdx] > healths[currIdx]){
                        healths[topIdx] -= 1 ;
                        healths[currIdx] = 0 ;
                        st.push(topIdx) ;
                    }
                    else if (healths[topIdx]<healths[currIdx]){
                        healths[currIdx] -= 1 ;
                        healths[topIdx] = 0 ;
                    }else{
                        healths[topIdx] = 0 ;
                        healths[currIdx] = 0 ;
                    }
                }
            }
        }for(int i = 0 ;i < n ;i ++) {
            if(healths[i]>0){
                result.push_back(healths[i]);
            }
        }
        return result ;
        

    }
};