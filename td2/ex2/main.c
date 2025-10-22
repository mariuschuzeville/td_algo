#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "utils.h"

#define N 10000

int main(void)
{
    int *arr = malloc(N*sizeof(int));
    int *tmp = malloc(N*sizeof(int)); 
    int *copy = malloc(N*sizeof(int)); 
    for (int i = 0; i < N; i++){
        arr[i] = rand() % 100000;
    }
    double start,end;
    copy_array(arr, copy, N);
    start = clock();
    selection_sort(copy, N);
    end = clock();
    printf("Selection Sort : %f s\n", (end-start)/CLOCKS_PER_SEC);
    copy_array(arr, copy, N);
    start = clock();
    insertion_sort(copy, N);
    end = clock();
    printf("Insertion Sort : %f s\n", (end-start)/CLOCKS_PER_SEC);
    copy_array(arr, copy, N);
    start = clock();
    bubble_sort(copy, N);
    end = clock();
    printf("Bubble Sort : %f s\n", (end-start)/CLOCKS_PER_SEC);
    copy_array(arr, copy, N);
    start = clock();
    mergesort_rec(copy, tmp, 0, N-1);
    end = clock();
    printf("Merge Sort : %f s\n", (end-start)/CLOCKS_PER_SEC);
    copy_array(arr, copy, N);
    start = clock();
    quick_sort_rec(copy, 0, N-1);
    end = clock();
    printf("Quick Sort : %f s\n", (end-start)/CLOCKS_PER_SEC);
    return 0;
}
