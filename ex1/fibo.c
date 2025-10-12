#include "fibo.h"

long long int fibo_naive(int n){
    if (n==0||n==1){
        return n;
    }
    else {return fibo_naive(n-1)+fibo_naive(n-2);}
}

long long int fibo_dyna(int n,long long int tableau[]){
    if (n<=1){return n;}
    else if (tableau[n]!=-1){return tableau[n];}
    else {
        tableau[n]=fibo_dyna(n-1,tableau)+fibo_dyna(n-2,tableau);
        return tableau[n];
    }
}