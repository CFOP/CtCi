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

void removeDups(Node *head){
    if(!head)return;

    std::unordered_set<int> st;
    st.insert(head->data);
    for(Node *p=head->next, *last=head ; p; p=p->next){
        if(st.find(p->data)==st.end()){
            st.insert(p->data);
            last = p;
        }
        else {
            last->next = p->next;
            free(p);
            p=last;
        }
    }
}

int main(){
    Node *head = new Node(3);

    head -> add(4);
    head -> add(3);
    head -> add(2);
    head -> add(3);
    head -> add(3);
    head -> add(8);

    head->print();
    removeDups(head);
    head->print();

    return 0;
}
