//
// Created by Jeronimo on 2019-11-23.
//

#ifndef _9_FUNCIONES_H
#define _9_FUNCIONES_H

#include <iostream>
#include <vector>
#include <thread>
#include <time.h>

#define MAX 20

using namespace std;


int n;
bool found = false;
int part = 0;

vector<int> arr;



void* search(void *arg){

    int thread_part = part++;
    int mid;

    int min = thread_part * (arr.size() / 4);
    int max = (thread_part + 1) * (arr.size() / 4);

    while (min < max && !found)  {
        mid = (max - min) / 2 + min;

        for(auto it=begin(arr); it!=end(arr);it++) {
            if (*(it+mid) == n) {
                found = true;
                break;
            } else if (*(it+mid) > n)
                max = mid - 1;
            else
                min = mid + 1;
        }
    }
}

void print(std::vector<int> &vec){

    std::vector<int>::iterator it = vec.begin();
    while(it != vec.end())
        std::cout<<(*it++)<<" ";

    std::cout<<std::endl;
}





#endif //_9_FUNCIONES_H
