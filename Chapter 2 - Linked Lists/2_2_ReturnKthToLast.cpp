#include <bits/stdc++.h>

struct Node{
    Node *next;
    int value;
    Node(int value):value(value){
        next = NULL;
    }
    void add(int value){
        Node *toAdd = new Node(value);
        Node *p;
        for(p=this; p->next; p = p->next);
        p->next = toAdd;
    }
};

Node* KthToLast(Node *head, int k){
    if(!head)return nullptr;
    Node *p = head;
    Node *ans;
    for(int i=0; i<k; i++, p=p->next){
        if(!p)
            return nullptr;
    }

    for(ans = head; p; ans = ans->next, p = p->next);

    return ans;
}

int main(){
    Node *head = new Node(1);

    head -> add(4);
    head -> add(3);
    head -> add(2);
    head -> add(3);
    head -> add(3);
    head -> add(8);

    std::cout<<KthToLast(head, 4)->value;
    return 0;
}
