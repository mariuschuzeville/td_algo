#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search.h"
#include "utils.h"

int main(void)
{
    int *arr = (int[]) {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
        10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
        20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
        30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
        40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
        50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
        60, 61, 62, 63, 64, 65, 66, 67, 68, 69,
        70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
        80, 81, 82, 83, 84, 85, 86, 87, 88, 89,
        90, 91, 92, 93, 94, 95, 96, 97, 98, 99
    };
    int n=100;
    int target=95;
    if (!(is_sorted_nondecreasing(*arr,n))){
        printf("Le tableau n'est pas trié\n");
        return 0;
    }
    clock_t debut, fin;
    float temps_linear=0;
    float temps_jump=0;
    float temps_binary=0;
    long long int resultat_linear;
    long long int resultat_jump;
    long long int resultat_binary;
    debut = clock();
    resultat_linear = linear_search(*arr,n,target);
    fin = clock();
    temps_linear = ((double)(fin - debut)) / CLOCKS_PER_SEC;
    debut = clock();
    resultat_jump = jump_search(*arr,n,target);
    fin = clock();
    temps_jump = ((double)(fin - debut)) / CLOCKS_PER_SEC;
    debut = clock();
    resultat_binary = binary_search(*arr,n,target);
    fin = clock();
    temps_binary = ((double)(fin - debut)) / CLOCKS_PER_SEC;
    printf("\nRésultats pour n = %d\n", n);
    printf("Linear search: %f (temps = %f s)\n", resultat_linear, temps_linear);
    printf("Jump search: %f (temps = %f s)\n", resultat_jump, temps_jump);
    printf("Binary search: %f (temps = %f s)\n", resultat_binary, temps_binary);
    return 0;
}
