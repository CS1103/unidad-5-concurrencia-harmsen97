#include <iostream>
#include <thread>
#include <vector>



template<typename T>

void print(T i){
    for(auto it : i){
        std::cout << it << " ";
    }
}


template<typename Container>

void suma(Container &i, int num){

    for(auto& it : i){
        it += num;
    }
    print(i);
}



int main(){

    std::vector<int> numeros{1,2,3,4,5,6,7,8,9};
    int num;

    std::cout<<"Ingrese un número: ";
    std::cin>>num;

    std::thread t1(suma<std::vector<int>>, std::ref(numeros), num);

    t1.join();


}