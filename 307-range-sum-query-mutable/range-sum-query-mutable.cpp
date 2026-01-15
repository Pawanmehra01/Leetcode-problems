class NumArray {
public:
    vector<int>Tree;
    int n ;
    void buildSegTree(int i, int l ,int r ,vector<int>&nums){
        if(l==r){
        Tree[i] = nums[r];
        return ;
        }

        int mid =(l+r)/2 ;
        buildSegTree(2*i+1 ,l ,mid ,nums);
        buildSegTree(2*i+2,mid+1 ,r,nums);
        Tree[i] = Tree[2*i+1] + Tree[2*i+2];
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        Tree.resize(4*n,0);
        buildSegTree(0 ,0,n-1,nums);
    }
    
    void updateSegTree(int index , int val , int l , int r, int node){
    if(l==r){
        Tree[node] = val;
        return ;
    }
    int  mid = (l+r)/2 ;
    if(index<=mid){
       updateSegTree(index , val , l,mid,2*node+1);
    }
    else{
       updateSegTree(index, val , mid+1 ,r ,2*node+2);
    }
    Tree[node] = Tree[2*node + 1] + Tree[2*node+2 ];
    }

    void update(int index, int val) {
        int  i = 0 ;
        int  l = 0 ;
        int  r = n-1;
        updateSegTree(index,val,l,r,i);
    }
    int querySum(int left ,int right , int start ,int end,int node){
        if(left>end || right<start)return 0 ;
        int mid =(left+right)/2;
        if(left>=start && right<=end ){
            return Tree[node];
        }
        return querySum(left ,mid,start,end,2*node+1) + querySum(mid+1,right,start,end,   2*node+2);
    }
    
    int sumRange(int left, int right) {
        int start = 0 ;
        int end = n-1 ;
        return querySum(start,end ,left,right,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */