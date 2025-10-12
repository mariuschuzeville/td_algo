#include <stdio.h>
#include <time.h>
#include "prime.h"

int main() {
    int n;
    printf("valeur de n : ");
    scanf("%d", &n);
    clock_t debut, fin;
    float temps_naive=0;
    float temps_efficace=0;
    long long int resultat_naive;
    long long int resultat_efficace;
    debut = clock();
    resultat_naive = prime_naive(n);
    fin = clock();
    temps_naive = ((double)(fin - debut)) / CLOCKS_PER_SEC;
    debut = clock();
    resultat_efficace = prime_efficace(n, tableau);
    fin = clock();
    temps_dyna = ((double)(fin - debut)) / CLOCKS_PER_SEC;
    printf("\nRésultats pour n = %d\n", n);
    printf("Méthode naïve   : %f (temps = %f s)\n", resultat_naive, temps_naive);
    printf("Méthode efficace : %f (temps = %f s)\n", resultat_dyna, temps_dyna);
    return 0;
}