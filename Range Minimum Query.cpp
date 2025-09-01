/* The functions which
builds the segment tree */

void buildSegmentTree(int idx,int l,int r,int segmentTree[],int arr[]){
    if(l == r){
        segmentTree[idx] = arr[l];
        return;
    }
    int mid = l + (r-l)/2;
    buildSegmentTree(2*idx+1,l,mid,segmentTree,arr);
    buildSegmentTree(2*idx+2,mid+1,r,segmentTree,arr);
    
    segmentTree[idx] = min(segmentTree[2*idx+1],segmentTree[2*idx+2]);
}
int *constructST(int arr[], int n) {
    // Your code here
    int *segmentTree = new int[4*n];
    
    buildSegmentTree(0,0,n-1,segmentTree,arr);
    
    return segmentTree;
}

/* The functions returns the
 min element in the range
 from a and b */
 
 int QueryST(int start,int end,int idx,int l,int r,int st[]){
     
     if(r < start || end < l) return INT_MAX;
     
     if(l >= start && r <= end) return st[idx];
     
     int mid = l + (r-l)/2;
     
     return min(QueryST(start,end,2*idx+1,l,mid,st),QueryST(start,end,2*idx+2,mid+1,r,st));
     
 }
int RMQ(int st[], int n, int a, int b) {
    
    // Your code here
    return QueryST(a,b,0,0,n-1,st);
}
