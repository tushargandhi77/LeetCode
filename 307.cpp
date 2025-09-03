class NumArray {
public:
    int n;
    vector<int> segmentTree;

    void buildSegmentTree(int idx,int l,int r,vector<int>& nums,vector<int>& segmentTree){
        if(l == r){
            segmentTree[idx] = nums[l];
            return;
        }
        int mid = l + (r-l)/2;
        buildSegmentTree(2*idx+1,l,mid,nums,segmentTree);
        buildSegmentTree(2*idx+2,mid+1,r,nums,segmentTree);

        segmentTree[idx] = segmentTree[2*idx+1] + segmentTree[2*idx+2];
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        segmentTree.resize(4*n);
        buildSegmentTree(0,0,n-1,nums,segmentTree);
    }

    void updateSegment(int index,int val,int idx,int l,int r){
        if(l==r){
            segmentTree[idx] = val;
            return;
        }
        int mid = l + (r-l)/2;
        if(index <= mid){
            updateSegment(index,val,2*idx+1,l,mid);
        }
        else{
            updateSegment(index,val,2*idx+2,mid+1,r);
        }

        segmentTree[idx] = segmentTree[2*idx+1] + segmentTree[2*idx+2];
    }

    void update(int index, int val) {
        updateSegment(index,val,0,0,n-1);
    }
    
    int rangeSum(int start,int end,int idx,int l,int r){
        if(r < start || l > end) return 0;

        if(l >= start && r <= end) return segmentTree[idx];

        int mid = l + (r-l)/2;
        return rangeSum(start,end,2*idx+1,l,mid) + rangeSum(start,end,2*idx+2,mid+1,r);
    }
    int sumRange(int left, int right) {
        return rangeSum(left,right,0,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
