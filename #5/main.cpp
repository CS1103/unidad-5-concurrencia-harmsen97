#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <time.h>

#define MAX 12

#define THREAD_MAX 4

using namespace std;

int part = 0;
vector<int> arr;
int elem = 0;
int finalArray[MAX];
int resta[THREAD_MAX];

vector<int> removeAllMatchingElements_Efficient(int lower, int higher, int id)
{
    vector<int> elements;
    for (size_t i = lower; i <= higher; i++)
    {
        if (arr[i] != elem) elements.push_back(arr[i]);
        else resta[id]++;
    }
    return elements;
}

int sumResta(int id)
{
    if (id == -1)
        return 0;
    
    int suma = 0;
    for (size_t i = 0; i <= id; i++)
    {
        suma += resta[i];
    }
    return suma;
}

void* removeAllMatchingElements_Efficient(void* arg)
{
    int thread_part = part++;
    int low = ((thread_part) * MAX/THREAD_MAX);
    int high = (((thread_part+1) * MAX/THREAD_MAX) - 1);

    vector<int> elements = removeAllMatchingElements_Efficient(low, high, thread_part);

    for (size_t i = 0; i < elements.size(); i++)
    {
        finalArray[low + i - sumResta(thread_part-1)] = elements[i];
    }

}

void displayVector(std::vector<int> & vec)
{
    std::vector<int>::iterator it = vec.begin();
    while(it != vec.end())
        std::cout<<(*it++)<<" ";
    std::cout<<std::endl;
}

int main()
{

    std::fill_n(finalArray, MAX, -1);

    srand(time(nullptr));
    for (int i = 0; i < MAX; i++)
        arr.push_back(rand() % 10);

    displayVector(arr);

    pthread_t threads[THREAD_MAX];

    // cracion de threads
    for (int i = 0; i < THREAD_MAX; i++)
        pthread_create(&threads[i], NULL, removeAllMatchingElements_Efficient, (void*)NULL);


    for (int i = 0; i < THREAD_MAX; i++)
        pthread_join(threads[i], NULL);

    for (size_t i = 0; i < MAX - sumResta(THREAD_MAX-1); i++)
    {
        cout << finalArray[i] << " ";
    }

    return 0;
}