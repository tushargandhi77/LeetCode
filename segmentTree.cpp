#include<bits/stdc++.h>
using namespace std;

vector<int> nums;
vector<int> segmentTree;

void buildSegmentTree(int i,int l,int r){
    if(l == r){
        segmentTree[i] = nums[l];
        return;
    }
    int mid = l + (r-l)/2;
    buildSegmentTree(2*i+1,l,mid);
    buildSegmentTree(2*i+2,mid+1,r);
    segmentTree[i] = segmentTree[2*i+1]+segmentTree[2*i+2];
}

int main() {
    nums = {1,2,3,4,5};
    int n = nums.size();
    segmentTree.resize(2*n,0);
    
    buildSegmentTree(0,0,n-1);
    
    
    for(int& num: segmentTree){
        cout<<num<<endl;
    }

    return 0;
}
