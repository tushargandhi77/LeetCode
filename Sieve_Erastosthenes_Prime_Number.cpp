vector<bool> isPrime(n+1,true);
        
        isPrime[0] = false;
        isPrime[1] = false;

        int idx = 2;
        while(idx <= n){
            if(isPrime[idx] == true){
                int i = 2;

                while(idx*i <= n){
                    isPrime[i*idx] = false;
                    i++;
                }
            }
            idx++;
        }
