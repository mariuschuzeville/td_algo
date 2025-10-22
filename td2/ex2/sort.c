#include <stdlib.h>
#include "sort.h"
#include "utils.h"

void selection_sort(int *arr, int n)
{
    int min=0;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if (arr[i]<arr[j]){
                min=j;
            }
        }
        swap(arr[i],arr[min]);
    }
    return arr;
}

void insertion_sort(int *arr, int n)
{
    int j=0;
    int key=0;
    for(int i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
    return arr;
}

void bubble_sort(int *arr, int n)
{
    for (int j=0;j<n;j++){
        for(int i=0;i<n-1;i++){
            if (arr[i]>arr[i+1]){
                swap(arr[i],arr[i+1]);
            }
        }
    }
    return arr;
}

void merge(int *arr, int *tmp, int l, int m, int r)
{
    int i = l;      
    int j = m + 1;  
    int k = l;
    while (i <= m && j <= r){
        if (arr[i]<=arr[j])
            tmp[k++] = arr[i++];
        else
            tmp[k++] = arr[j++];
    }
    while (i <= m)
        tmp[k++] = arr[i++];
    while (j <= r)
        tmp[k++] = arr[j++];
    for (int p = l; p <= r; p++)
        arr[p] = tmp[p];
}

void mergesort_rec(int *arr, int *tmp, int l, int r)
{
    if (l < r){
        int m = (l + r) / 2;
        mergesort_rec(arr, tmp, l, m);
        mergesort_rec(arr, tmp, m + 1, r);
        merge(arr, tmp, l, m, r);
    }
}

void merge_sort(int *arr, int n)
{
    if (!arr || n <= 1)
        return;
    int *tmp = (int *)malloc((size_t)n * sizeof(int));
    if (!tmp)
        return;
    mergesort_rec(arr, tmp, 0, n - 1);
    free(tmp);
}
int partition(int *arr, int l, int r)
{
    int p = arr[r]; 
    int i = l-1;
    for (int j=l; j<r; j++){
        if (arr[j]<=p){
            i++;
            swap_int(&arr[i], &arr[j]);
        }
    }
    swap_int(&arr[i+1], &arr[r]);
    return i+1;
}

void quick_sort_rec(int *arr, int l, int r)
{
    if (l<r){
        int p = partition(arr, l, r);
        quick_sort_rec(arr,l,p-1);
        quick_sort_rec(arr, p+1,r);
    }
}

void quick_sort(int *arr, int n)
{
    if (!arr || n <= 1)
        return;
    quick_sort_rec(arr, 0, n - 1);
}