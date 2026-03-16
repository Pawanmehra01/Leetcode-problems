class Solution {
public:
    typedef long long ll ;
    bool is_it_Possible(vector<int>& ranks,int cars,ll mid){
        ll no_of_cars = 0 ;
        for(int i = 0 ;i < ranks.size() ;i ++){
            no_of_cars += sqrt(mid/ranks[i]);
        }
        return no_of_cars>=cars ;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        ll  l  = 1 ;
        int maxElement = *max_element(begin(ranks),end(ranks)) ;
        ll  r = 1LL*maxElement * cars * cars  ;
        ll result = -1 ;
        while(l<=r){
            ll mid  = l + (r-l)/2 ;

            if(is_it_Possible(ranks,cars,mid)){
                result = mid ;
                r =  mid - 1 ;
            }else{
                l = mid + 1 ;
            }
        }
        return result ;
    }
};