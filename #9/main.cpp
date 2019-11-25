#include <iostream>

#include "funciones.h"



int main(){

    cout<<"Ingrese n: ";

    srand(time(nullptr));
    for (int i = 0; i < MAX; i++)
        arr.push_back(rand() % 20);

    cin >> n;
    auto nt = thread::hardware_concurrency();
    vector<pthread_t> threads(nt);

    for (int i = 0; i < nt; i++)
        pthread_create(&threads[i], NULL, search, (void *) NULL);

    for (int i = 0; i < nt; i++)
        pthread_join(threads[i], NULL);

    if (found)
        cout << n <<endl<< "n fue encontrado " << endl;

    else
        cout << n<<endl << "n no fue encontrado en el vector aleatorio" << endl;

    print(arr);

    return 0;
}