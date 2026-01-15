class NumArray {
public:
    vector<int>res;
    NumArray(vector<int>& nums) {
    int  n  = nums.size();
    res.resize(n,0);
    int sum  = 0;

    for(int i = 0 ;i < n ;i ++ ){
        sum = sum +nums[i];
        nums[i]= sum ;
        res[i]= nums[i];
       }

    }
    
    int sumRange(int left, int right) {
        if(left==0)return res[right];
        else{
            return res[right]- res[left-1];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */