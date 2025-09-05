class Solution {
public:
    int n;
    vector<int> segmentTree;

    void buildSegmentTree(int idx,int l,int r,vector<int>& segmentTree,vector<int>& heights){
        if(l == r){
            segmentTree[idx] = l;
            return;
        }
        int mid = l + (r-l)/2;
        buildSegmentTree(2*idx+1,l,mid,segmentTree,heights);
        buildSegmentTree(2*idx+2,mid+1,r,segmentTree,heights);

        int leftIdx = segmentTree[2*idx+1];
        int rightIdx = segmentTree[2*idx+2];

        if(heights[leftIdx] >= heights[rightIdx]){
            segmentTree[idx] = leftIdx;
        }
        else{
            segmentTree[idx] = rightIdx;
        }
    }

    int RIMQ(int start,int end,int idx,int l,int r,vector<int>& segmentTree,vector<int>& arr){
        if(r < start || end < l ) return -1;

        if(l >= start && r <= end) return segmentTree[idx];

        int mid = l + (r-l)/2;

        int leftIdx = RIMQ(start,end,2*idx+1,l,mid,segmentTree,arr);

        int rightIdx = RIMQ(start,end,2*idx+2,mid+1,r,segmentTree,arr);

        if(leftIdx == -1) return rightIdx;
        if(rightIdx == -1) return leftIdx;

        if(arr[leftIdx] >= arr[rightIdx]){
            return leftIdx;
        }
        else{
            return rightIdx;
        }
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        n = heights.size();
        segmentTree.resize(4*n);
        vector<int> result;

        buildSegmentTree(0,0,n-1,segmentTree,heights);

        for(auto& query: queries){
            int alice = min(query[0],query[1]);
            int bob = max(query[0],query[1]);

            if(alice == bob || heights[bob] > heights[alice]){
                result.push_back(bob);
                continue;
            }

            int l = bob+1;
            int r = n-1;
            int result_idx = -1;

            int threshold = max(heights[alice],heights[bob]);

            // binary Search
            while(l <= r){
                int mid = l + (r-l)/2;

                int leftIdx = RIMQ(l,mid,0,0,n-1,segmentTree,heights);

                if(heights[leftIdx] > threshold){
                    r = mid-1;
                    result_idx = leftIdx;
                }
                else{
                    l = mid + 1;
                }
            }

            result.push_back(result_idx);
        }

        return result;
    }
};
