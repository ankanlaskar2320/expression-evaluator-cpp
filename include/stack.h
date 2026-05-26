#ifndef STACK_H
#define STACK_H

#include <iostream>

template <typename T>
class stack {

private :

    struct node{
        T data; //value is stored
        node*next; 
        //constructore to add new node
        node(T value){
            data=value;
            next=nullptr;
        }
    };

    node* top;
    int size;

public :

    //constructor 
    stack(){
        top= nullptr;
        size=0;
    }

    //destructor
    ~stack(){
        while (isEmpty()==false){
            pop();
        }
    }

    void push(T value){
        node* newNode = new node(value);
        newNode->next = top;
        top=newNode;
        size=size+1;
    }

    void pop(){
        if(isEmpty()==true){
            std::cout<<"error: stack is empty ,cannot pop\n";
            return;
        }
        node*temp = top;
        top = top->next;
        delete temp;
        size= size - 1;
    }

    T peek(){
        if(isEmpty()==true){
            std::cout<<"error: stack is empty, cannot peek";
            exit(1);
        }
        return top->data;
    }

    bool isEmpty(){
        if(top==nullptr){
            return true;
        }
        return false;
    }

    int getSize(){
        return size;
    }
};

#endif