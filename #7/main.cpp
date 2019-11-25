#include <iostream>
#include <pthread.h>
#include <time.h>


#include "funciones.h"

#define THREAD_MAX 4

using namespace std;



int part = 0;

void* merge_sort(void* arg)
{

    int thread_part = part++;


    int low = thread_part * (MAX / 4);
    int high = (thread_part + 1) * (MAX / 4) - 1;


    int mid = low + (high - low) / 2;
    if (low < high) {
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    }
}


int main()
{

    for (int i = 0; i < MAX; i++)
        arr[i] = rand() % 100;


    clock_t t1, t2;

    t1 = clock();
    pthread_t threads[THREAD_MAX];

    for (int i = 0; i < THREAD_MAX; i++)
        pthread_create(&threads[i], NULL, merge_sort,
                                        (void*)NULL);


    for (int i = 0; i < 4; i++)
        pthread_join(threads[i], NULL);


    merge(0, (MAX / 2 - 1) / 2, MAX / 2 - 1);
    merge(MAX / 2, MAX/2 + (MAX-1-MAX/2)/2, MAX - 1);
    merge(0, (MAX - 1)/2, MAX - 1);

    t2 = clock();


    cout << "Array ordenado: ";
    for (int i = 0; i < MAX; i++)
        cout << arr[i] << " ";


    return 0;

    }