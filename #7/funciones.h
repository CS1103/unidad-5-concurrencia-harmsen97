//
// Created by Jeronimo on 2019-11-21.
//

#ifndef MERGECONTHREADS_FUNCIONES_H
#define MERGECONTHREADS_FUNCIONES_H

#include <iostream>
#include <pthread.h>
#include <time.h>

#define MAX 100

int arr[MAX];

void merge(int min, int med, int max)
{
    int* left = new int[med - min + 1];
    int* right = new int[max - med];


    int n1 = med - min + 1;
    int n2 = max - med;
    int i;
    int j;


    for (i = 0; i < n1; i++)
        left[i] = arr[i + min];


    for (i = 0; i < n2; i++)
        right[i] = arr[i + med + 1];

    int k = min;
    i = j = 0;


    while (i < n1 && j < n2) {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }


    while (i < n1) {
        arr[k++] = left[i++];
    }


    while (j < n2) {
        arr[k++] = right[j++];
    }
}


void merge_sort(int menor, int mayor)
{

    int med = menor + (mayor - menor) / 2;

    if (menor < mayor) {


        merge_sort(menor, med);


        merge_sort(med + 1, mayor);


        merge(menor, med, mayor);
    }
}






#endif //MERGECONTHREADS_FUNCIONES_H
