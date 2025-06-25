// Binary search on answer

class Solution {
public:
    long long findCountsmallest(vector<int>& nums1, vector<int>& nums2, long long midProduct){
        long long productsCount = 0;

        int n = nums2.size();
        for(int i = 0;i<nums1.size();i++){

            if(nums1[i] >= 0){
                int l = 0;
                int r = n - 1;
                int m = -1;

                while(l <= r){
                    int mid = l + (r-l)/2;

                    long long prod = 1LL * nums1[i] * nums2[mid];

                    if(prod <= midProduct){
                        m = mid;
                        l = mid + 1;
                    }
                    else{
                        r = mid - 1;
                    }
                }

                productsCount += (m+1);

            }
            else{
                // product will be negative right hand side will contain smaller products
                int l = 0;
                int r = n-1;
                int m = n;

                while(l <= r){
                    int mid = l + (r-l)/2;

                    long long product = 1LL * nums1[i] * nums2[mid];

                    if(product <= midProduct){
                        m = mid;
                        r = mid - 1;
                    }
                    else{
                        l = mid + 1;
                    }
                }

                productsCount += (n - m);
            }
        }

        return productsCount;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long result = 0;

        long long l = -1e10;
        long long r = 1e10;

        while(l<=r){
            long long midProduct = l  + (r-l)/2;

            // check if this k smallest or not

            long long countsmallest = findCountsmallest(nums1,nums2,midProduct);

            if(countsmallest >= k){
                result = midProduct;
                r = midProduct - 1 ;
            }
            else{
                l = midProduct + 1;
            }
        }

        return result;
    }
};

// Brute Force TLE

class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        priority_queue<long long> pq;

        for(int i = 0;i<nums1.size();i++){
            for(int j = 0;j<nums2.size();j++){
                pq.push((long long)nums1[i]*nums2[j]);

                if(pq.size() > k){
                    pq.pop();
                }
            }
        }

        return pq.top();
    }
};
