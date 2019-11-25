//
// Created by Jeronimo on 2019-11-24.
//

#ifndef _6_FUNCIONES_H
#define _6_FUNCIONES_H

#include <iostream>
#include <thread>
#include <vector>


using namespace std;

class Node
{
private:
    int data;
    Node *next;
public:
    Node(int new_data){
        data=new_data;
        next=NULL;
    }
    int getData(){
        return data;
    }
    void setData(int new_data){
        data=new_data;
    }

    Node* goNext(int i){
        while(i>=1){
            if(i==1){
                return next;
            }
            else{
                next->setNext(next->goNext(1));
            }
            i=i-1;
        }
    }

    void setNext(Node *new_next){
        next=new_next;
    }

};


void append(Node* head_ref, int new_data)
{
    Node* new_node = new Node(new_data);

    Node *last = head_ref;

    new_node->setData(new_data);

    new_node->setNext(NULL);

    if (head_ref == NULL)
    {
        head_ref = new_node;
        return;
    }
    while (last->goNext(1)!= NULL)
        last = last->goNext(1);

    last->setNext(new_node);
}


void printList(Node *node)
{
    while (node != NULL)
    {
        cout<<" "<<node->getData();
        node = node->goNext(1);
    }
}


#endif //_6_FUNCIONES_H
