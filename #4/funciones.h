//
// Created by Jeronimo on 2019-11-25.
//

#ifndef _4_FUNCIONES_H
#define _4_FUNCIONES_H

#include <iostream>
#include <string>
#include <future>
#include <vector>

using namespace std;



void Fibonacci(unsigned int n, promise<unsigned int> *p1){
    vector<int> fibo;
    if(n==0)
        p1->set_value(0);
    int presente = 0;
    int siguiente = 1;
    int temp = 0;

    for (int i = 1; i <= n; i++){


        temp = presente + siguiente;
        presente = siguiente;
        siguiente = temp;
        fibo.push_back(siguiente);
    }

    for(auto &i:fibo)
        cout<<i<< " ";

    p1->set_value(siguiente);

};



#endif //_4_FUNCIONES_H
