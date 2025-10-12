#include <stdio.h>
#include <time.h>
#include "fibo.h"

int main() {
    int n;
    printf("valeur de n : ");
    scanf("%d", &n);
    clock_t debut, fin;
    float temps_naive=0;
    float temps_dyna=0;
    long long int resultat_naive;
    long long int resultat_dyna;
    debut = clock();
    resultat_naive = fibo_naive(n);
    fin = clock();
    temps_naive = ((double)(fin - debut)) / CLOCKS_PER_SEC;
    long long int tableau[n + 1];
    for (int i=0;i<n;i++){
        tableau[i]=-1
    }
    debut = clock();
    resultat_dyna = fibo_dyna(n, tableau);
    fin = clock();
    temps_dyna = ((double)(fin - debut)) / CLOCKS_PER_SEC;
    printf("\nRésultats pour n = %d\n", n);
    printf("Méthode naïve   : %f (temps = %f s)\n", resultat_naive, temps_naive);
    printf("Méthode dynamique : %f (temps = %f s)\n", resultat_dyna, temps_dyna);
    return 0;
}
