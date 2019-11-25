#include <iostream>
#include <thread>
#include <vector>

#include "funciones.h"


using namespace std;


int main() {

    auto creatorNodes = [](Node* head_ref,int new_data){
        
        Node* new_node = new Node(new_data);
        Node *last = head_ref;
        new_node->setData(new_data);
        new_node->setNext(NULL);

        while (last->goNext(1)!= NULL)
            last = last->goNext(1);
        last->setNext(new_node);
    };

    Node *pmyNode=new Node(20);


    thread t1 = thread(creatorNodes,pmyNode,30);
    t1.join();
    thread t2 = thread(creatorNodes,pmyNode->goNext(1),40);
    t2.join();
    thread t3 = thread(creatorNodes,pmyNode->goNext(2),50);
    t3.join();
    thread t4 = thread(creatorNodes,pmyNode->goNext(3),60);
    t4.join();

    printList(pmyNode);

    return 0;
}