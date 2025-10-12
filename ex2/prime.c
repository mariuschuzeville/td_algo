int prime_naive(int n){
    int c=0;
    for (int i=0,i<=n,i++){
        for (int j=0,j<=n**(1/2),j++){
            if (i*j==n){c++;}
        }
    }
    return c;
}

int prime_efficace(int n){
    int prime[n+1];
    for (int i = 0; i < n; i++)
        prime[i] = 1; 
    prime[0] = 0;
    prime[1] = 0;
    for (int i = 2; i*i<n;i++) {
        if (prime[i]!=0) {
            for (int j=i*i; j<n; j+=i)
                prime[j] = 0;
        }
    }
    int c = 0;
    for (int i = 2; i<n; i++)
        if (is_prime[i]){
            c++;
        }

    return c;
}
