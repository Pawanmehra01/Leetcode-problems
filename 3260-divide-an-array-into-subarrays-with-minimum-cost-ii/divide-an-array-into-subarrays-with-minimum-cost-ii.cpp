class Solution {
public:
    typedef long long ll ;
    typedef pair<ll,ll>P;
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        set<P>kminimum ;
        set<P>remaining;

        ll sum = 0 ;
        int i=1 ;
        while(i-dist<1){
            kminimum.insert({nums[i],i});
            sum+=nums[i];
            if(kminimum.size() >k-1){
                P temp =*kminimum.rbegin();
                sum-= temp.first;
                remaining.insert(temp);
                kminimum.erase(temp);
            }
            i++;
        }
        ll result = LONG_MAX; ;
        while(i<n){
            kminimum.insert({nums[i],i});
            sum +=nums[i];
            if(kminimum.size() >k-1){
                P temp = *kminimum.rbegin();
                sum-= temp.first;
                remaining.insert(temp);
                kminimum.erase(temp);
            }
            result = min(result,sum);

            //shift window 
            P remove = {nums[i-dist],i-dist};
            if(kminimum.count(remove)){
                kminimum.erase(remove);
                sum-= remove.first ;

                if(!remaining.empty()){
                    P temp = *remaining.begin();
                    kminimum.insert(temp);
                    sum+= temp.first ;
                    remaining.erase(temp);
                }
            }else{
                remaining.erase(remove);
            }
            i++;
        }
        return nums[0] + result ;
    }
};