vector<bool> isPrime(n+1,true);
        
        isPrime[0] = false;
        isPrime[1] = false;

        int idx = 2;
        while(idx <= n){
            if(isPrime[idx] == true){
                int i = 2;

                while(idx*i <= n){
                    isPrime[i*idx] = false; // // n/2 + n/3 + n/7 + ....  harmonic serires on  primes very slow related to log(n) 
                    i++;
                }
            }
            idx++;
        }

// n(1/2 + 1/3 + ... )
// TC - O( n * log(log(n))
