#include <bits/stdc++.h>

struct Node{
    int data;
    Node *next;

    Node (int data):data(data){
        next = NULL;
    }

    void add(int data){
        if(next)
            next->add(data);
        else {
            Node *toAdd = new Node(data);
            next = toAdd;
        }
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

void partition(Node *head, int x){
    Node *p = head;
    while(p && head && p->data < x)
        head = p = head->next;
    for(;p;p = p->next){
        if(p->data < x){
            std::swap(p->data, head->data);
            head = head->next;
        }
    }
}

int main(){
    Node *head = new Node(3);
    head -> add(8);
    head -> add(5);
    head -> add(2);
    head -> add(9);
    head -> add(1);
    head -> add(5);
    head -> add(1);
    head -> add(9);

    head -> print();
    partition(head, 3);
    head -> print();


    return 0;
}
