class NumArray {
public:
    vector<int> Tree;
    int n;

    void buildSegTree(int node, int l, int r, vector<int>& nums) {
        if (l == r) {
            Tree[node] = nums[l];
            return;
        }
        int mid = (l + r) / 2;
        buildSegTree(2 * node + 1, l, mid, nums);
        buildSegTree(2 * node + 2, mid + 1, r, nums);
        Tree[node] = Tree[2 * node + 1] + Tree[2 * node + 2];
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        Tree.resize(4 * n);
        buildSegTree(0, 0, n - 1, nums);
    }

    void updateSegTree(int index, int val, int l, int r, int node) {
        if (l == r) {
            Tree[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (index <= mid)
            updateSegTree(index, val, l, mid, 2 * node + 1);
        else
            updateSegTree(index, val, mid + 1, r, 2 * node + 2);

        Tree[node] = Tree[2 * node + 1] + Tree[2 * node + 2];
    }

    void update(int index, int val) {
        updateSegTree(index, val, 0, n - 1, 0);
    }

    int querySum(int left, int right, int ql, int qr, int node) {
        if (qr < left || ql > right)
            return 0;

        if (ql <= left && right <= qr)
            return Tree[node];

        int mid = (left + right) / 2;
        return querySum(left, mid, ql, qr, 2 * node + 1) +
               querySum(mid + 1, right, ql, qr, 2 * node + 2);
    }

    int sumRange(int left, int right) {
        return querySum(0, n - 1, left, right, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */