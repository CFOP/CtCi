#include <bits/stdc++.h>

struct Node{
    int data;
    Node *next;

    Node(int data):data(data){

    }

    void add(int data){
        if(next){
            next->add(data);
        }
        else {
            Node *toAdd = new Node(data);
            next = toAdd;
        }
    }

    void add(Node *toAdd){
        if(next){
            next->add(toAdd);
        }
        else {
            next = toAdd;
        }
    }

    void print(){
        std::cout<<data<<" ";
        if(next)
            next->print();
        else
            std::cout<<"\n";
    }
};

Node* intersection(Node *a, Node *b){
    if(!a || !b)
        return nullptr;

    std::stack<Node*> aStack;
    std::stack<Node*> bStack;

    for(;a;a=a->next)
        aStack.push(a);
    for(;b;b=b->next)
        bStack.push(b);

    Node *intern = nullptr;
    while(aStack.size() && bStack.size()){
        if(aStack.top()==bStack.top())
            intern = aStack.top();
        else break;
        aStack.pop();
        bStack.pop();
    }

    return intern;
}

int main(){
    Node *lista = new Node(1);
    lista->add(2);
    lista->add(3);
    lista->add(4);
    lista->add(4);

    Node *a = new Node(5);
    a -> add(6);
    a -> add(7);
    a -> add(8);
    a -> add(lista);

    Node *b = new Node(9);
    b -> add(10);
    b -> add(lista);

    //lista->print();
    a->print();
    b->print();

    if(intersection(a, b))
        intersection(a, b)->print();
    else std::cout<<"NOT";

    return 0;
}
