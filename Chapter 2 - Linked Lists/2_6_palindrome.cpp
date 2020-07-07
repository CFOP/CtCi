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

};

// 111222

bool verifyPalindrome(Node **first, Node *last){
    if(!last || !*first)
        return true;
    if(!verifyPalindrome(first, last->next))
        return false;
    if((*first)->data!=last->data)
        return false;
    *first = (*first)->next;
    if(*first == last){
        *first = NULL;
    }
    return true;

}

bool isPalindrome(Node *head){
    if(!head)
        return false;
    return verifyPalindrome(&head, head);
}

int main(){

    Node *lista = new Node(1);
    lista->add(2);
    lista->add(3);
    lista->add(4);
    lista->add(3);
    lista->add(2);
    lista->add(1);
    //lista->add(0);

    std::cout<<isPalindrome(lista);

    return 0;
}
