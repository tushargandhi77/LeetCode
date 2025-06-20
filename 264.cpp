// Brute Force

class Solution {
public:
    int divide(int a,int b){
        while(a%b == 0){
            a = a/b;
        }
        return a;
    }

    bool isugly(int n){
        n = divide(n,2);
        n = divide(n,3);
        n = divide(n,5);

        return n == 1;
    }
    int nthUglyNumber(int n) {
        int count = 0;

        for(int i = 1;i<1e9;i++){
            if(isugly(i)){
                count++;
                if(count==n) return i;
            }
        }

        return -1;
    }
};

// Optimul
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> arr(n+1);

        int i2 = 1;
        int i3 = 1;
        int i5 = 1;

        arr[1] = 1;

        for(int i = 2;i<=n;i++){
            int i2ugly = arr[i2] * 2;
            int i3ugly = arr[i3] * 3;
            int i5ugly = arr[i5] * 5;

            int minugly = min({i2ugly,i3ugly,i5ugly});
            arr[i] = minugly;

            if(minugly == i2ugly){
                i2++;
            }
            if(minugly == i3ugly){
                i3++;
            }
            if(minugly == i5ugly){
                i5++;
            }
        }

        return arr[n];
    }
};
