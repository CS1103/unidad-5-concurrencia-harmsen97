//
// Created by Jeronimo on 2019-11-24.
//

#ifndef _1_FUNCIONES_H
#define _1_FUNCIONES_H

#include <iostream>
#include <thread>
#include <random>
#include <vector>
#include <future>

using namespace std;

random_device rd;

void exer1(){

    const size_t n = 1000;

    auto nt = thread::hardware_concurrency();
    auto range = n/nt;
    cout << "Cantidad: " << n << endl;
    cout << "Threads: " << nt << endl;
    cout << "Rango: " << range << endl;


    vector<int> vec(n);

    vector<thread> vec_thread(nt);

    auto filler = [&vec](size_t start, size_t stop){
        for (int i = start; i < stop; i++)
            vec[i] = rd() % 100;
    };
    for(int j=0; j<nt; j++)
        vec_thread[j] = thread(filler, range*j, range*(j+1));
    for(auto &t:vec_thread)
        t.join();
    for(auto &item:vec)
        cout<<item<<" ";
    cout<<endl;



    vector<promise<int>> vec_promise(nt);
    vector<future<int>> vec_future(nt);
    vector<thread> vec_thread2(nt);

    auto summarizer = [&vec](promise<int> &prom, size_t start, size_t stop){
        auto suma = 0;
        for (int i = start; i < stop; i++)
            suma += vec[i];
        prom.set_value(suma);
    };
    for (int i = 0; i < nt; i++)
        vec_future[i] = vec_promise[i].get_future();
    for (int i = 0; i < nt; i++)
        vec_thread2[i] = thread(summarizer,ref(vec_promise[i]),range*i,range*(i+1));
    for(int i = 0; i<nt; i++)
        vec_thread2[i].join();
    auto suma2 = accumulate(begin(vec_future),end(vec_future),0,
                            [](int a, future<int> &ftr){
                                return a + ftr.get();
                            });

    cout<<"Suma total: "<< suma2;

}

#endif //_1_FUNCIONES_H
