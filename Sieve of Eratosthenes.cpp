//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

//User function Template for C++
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N)
    {
        // Write Your Code here
        vector<int> result;
        
        vector<bool> isPrime(N+1,true);
        
        isPrime[0] = false;
        isPrime[1] = false;
        
        int idx = 2;
        while(idx <= sqrt(N)){
            if(isPrime[idx]){
                int i = 2;
                while(i*idx <= N){
                    isPrime[i*idx] = false;
                    i++;
                }
            }
            idx++;
        }
        
        for(int i = 2;i<=N;i++){
            if(isPrime[i]){
                result.push_back(i);
            }
        }
        return result;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends
