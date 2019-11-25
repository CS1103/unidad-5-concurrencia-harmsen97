//
// Created by Jeronimo on 2019-11-24.
//

#ifndef _3_FUNCIONES_H
#define _3_FUNCIONES_H

#include <thread>
#include <vector>
#include <future>
using namespace std;

bool isPrime(int num){
    bool flag=true;
    for(int i = 2; i <= num / 2; i++) {
        if(num % i == 0) {
            flag = false;
            break;
        }
    }
    return flag;
}

void Primes(){

    auto nt=5;
    int N;
    std::cout<<"Ingrese n:\n";
    std::cin>>N;

    std::vector<int> primeVector;




    vector<promise<vector<int>>> vec_promise(nt);
    vector<future<vector<int>>> vec_future(nt);
    vector<std::thread> vec_thread2(nt);


    for (int i = 0; i < nt; i++){
        vec_future[i] = vec_promise[i].get_future();
    }

    auto prime = [](std::promise<std::vector<int>> &prom, size_t position, size_t subSize){
        //cout<<"ID del thread: "<<this_thread::get_id()<<endl;
        std::vector<int> subVector;

        for(int number=position;number<position+subSize;number++){
            if(isPrime(number) && number!=0 && number!=1){
                subVector.push_back(number);
            }
        }
        prom.set_value(subVector);

    };

    int size=N/nt;
    int position=0;

    for (int i = 0; i < nt; i++){
        vec_thread2[i] = thread(prime,ref(vec_promise[i]),position,size);
        position=size+position;
    }

    for(int i = 0; i<nt; i++)
        vec_thread2[i].join();


    for(int i=0;i<nt;i++){
        auto respFuture = vec_future[i].get();
        for(int primo : respFuture){
            primeVector.push_back(primo);
        }
    }
    cout<<"Numeros Primes menores que N:"<<endl;

    for(int primo: primeVector)
        cout<<primo<<endl;

}


#endif //_3_FUNCIONES_H
