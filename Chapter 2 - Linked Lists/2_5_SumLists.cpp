#include <bits/stdc++.h>

class Node{
public:
    Node *next;
    int data;

    Node(int data):data(data){
        next= NULL;
    }

    void add(int d){
        Node *toAdd = new Node(d);
        Node *i;
        for(i=this; i->next; i = i->next);
        i->next = toAdd;
    }

    void print(){
        std::cout<<data;
        if(next){
            std::cout<<" ";
            next->print();
        }
        else std::cout<<"\n";
    }
};

Node *sumList(Node *head1, Node *head2){

    int diference=0;
    Node *a;
    Node *b;
    for(a = head1, b = head2; a && b; a = a->next, b = b->next);
    if(b){
        std::swap(a, b);
        std::swap(head1, head2);
    }

    for(;a;a=a->next)
        diference++;

    for(int i=0; i<diference; i++){
        Node *toAdd = new Node(0);
        toAdd->next = head2;
        head2 = toAdd;
    }

    std::stack<int> toAdd;
    for(a = head1, b = head2; a && b; a = a->next, b = b->next)
        toAdd.push(b->data+a->data);

    Node *result = NULL;
    while(toAdd.size()){
        Node *newNode = new Node(toAdd.top());
        toAdd.pop();
        newNode->next = result;
        result = newNode;
        if(newNode->data/10){
            if(toAdd.empty())
                toAdd.push(0);
            toAdd.top()+=newNode->data/10;
            newNode->data%=10;
        }
    }

    return result;
}

int main(){
    Node *a = new Node(9), *b = new Node(1);
    a -> add(9);
    a -> add(6);

    a->print();
    b->print();
    sumList(a, b)->print();
    return 0;
}
