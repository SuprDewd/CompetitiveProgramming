vi divisor_sieve(int n) {
    vi minimalDiv(n+1, 2), primes;
    if(n>=2) primes.push_back(2);
    minimalDiv[0] = 0;
    for(int k=1;k<=n;k+=2) minimalDiv[k] = k;
    for(int k=3;k<=n;k+=2) {
        if(minimalDiv[k] == k) primes.push_back(k);
        rep(i, 1, size(primes))
            if(primes[i] > minimalDiv[k] || primes[i]*k > n) break;
            else minimalDiv[primes[i]*k] = primes[i];
    }
    return primes; }

