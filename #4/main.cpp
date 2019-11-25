#include <iostream>

#include "funciones.h"

using namespace std;




int main() {

    int n;
    cout << "Ingrese n: ";
    cin >> n;
    auto* p1= new promise<unsigned int>();
    auto f1= p1->get_future();

    thread* t1= new thread(Fibonacci, n, p1);
    t1->join();

    return 0;



}