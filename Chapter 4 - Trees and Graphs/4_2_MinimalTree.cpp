#include <bits/stdc++.h>

struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int data):data(data){
        left = nullptr;
        right = nullptr;
    }
};

void printTree(Node *head){
    if(!head)
        return;
    std::cout<<head->data<<" ";
    printTree(head->left);
    printTree(head->right);
}

Node* buildDFS(const int *DATA, int left, int right){
    if(left>=right)
        return nullptr;
    int middle = (left+right)/2;
    Node *toAdd = new Node(DATA[middle]);
    toAdd ->left = buildDFS(DATA, left, middle);
    toAdd ->right = buildDFS(DATA, middle+1, right);
    return toAdd;
}

Node* buildBFS(const int *DATA, int size){

    std::queue<std::pair<int, int>> q; //left, right
    std::queue<Node*> toComplete;
    q.push(std::make_pair(0, size));
    Node *head = new Node(DATA[size/2]);
    toComplete.push(head);

    while(q.size()){

        int left(q.front().first), right(q.front().second);
        q.pop();
        Node *toAdd = toComplete.front();
        toComplete.pop();

        if(left+1>=right) continue;
        int middle = (left+right)/2;

        if(left<middle)
            toAdd->left = new Node(DATA[(left+middle)/2]);
        if((middle+1)<right)
            toAdd->right = new Node(DATA[(right+middle+1)/2]);

        toComplete.push(toAdd->left);
        q.push(std::make_pair(left, middle));

        toComplete.push(toAdd->right);
        q.push(std::make_pair(middle+1, right));

    }

    return head;
}

int main(){
    int DATA[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    printTree(buildDFS(DATA, 0, 10)); std::cout<<"\n";
    printTree(buildBFS(DATA, 10)); std::cout<<"\n";
    return 0;
}
