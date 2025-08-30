// User function Template for C++

class SegmentTree{
    public:
        int n;
        vector<int> segTree;
        SegmentTree(int size){
            n = size;
            segTree.resize(4*size);
        }
        
        void buildSegmentTree(int idx,int l,int r,int arr[]){
            if(l == r){
                segTree[idx] = arr[l];
                return;
            }
            
            int mid = l + (r-l)/2;
            buildSegmentTree(2*idx+1,l,mid,arr);
            buildSegmentTree(2*idx+2,mid+1,r,arr);
            
            segTree[idx] = segTree[2*idx+1] + segTree[2*idx+2];
        }
        
        int query(int start,int end,int idx,int l,int r){
            if(r < start || l > end){
                return 0;
            }
            
            if(l >= start && r <= end){
                return segTree[idx];
            }
            
            int mid = l + (r-l)/2;
            return query(start,end,2*idx+1,l,mid) + query(start,end,2*idx+2,mid+1,r);
        }
};
class Solution {
  public:
    vector<int> querySum(int n, int arr[], int q, int queries[]) {
        // code here
        SegmentTree s(n);
        
        s.buildSegmentTree(0,0,n-1,arr);
        
        vector<int> result;
        
        for(int i = 0;i<2*q;i+=2){
            int start = queries[i] - 1;
            int end = queries[i+1] - 1;
            
            result.push_back(s.query(start,end,0,0,n-1));
        }
        
        return result;
        
    }
};
