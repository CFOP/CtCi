#include <bits/stdc++.h>

struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int data):data(data){
        left = nullptr;
        right = nullptr;
    }

    int setLeft(int data){
        if(left){
            left->setLeft(data);
        }
        else {
            left = new Node(data);
        }
    }

    int setRight(int data){
        if(right){
            right->setRight(data);
        }
        else {
            right = new Node(data);
        }
    }
};

bool compare(Node *T1, Node *T2){
	if(!T1 || !T2)
		return T1 == T2;
	if(T1->data!=T2->data)
		return false;
	return compare(T1->right, T2->right) && compare(T1->left, T2->left);
}

bool isSubtree(Node *T1, Node *T2){
	if(!T2)
		return true;
	if(!T1)
		return false;
	if(T1->data == T2->data){
		if(compare(T1, T2))
			return true;
	}
	return isSubtree(T1->right, T2) || isSubtree(T1->left, T2);
}

int main(){
    Node *T1 = new Node(1);
    T1->setRight(4);
    T1->setRight(2);
    T1->right->right->setLeft(5);
    T1->setRight(1);
    T1->setRight(8);
    T1->setLeft(4);
    T1->left->setRight(1);
    T1->setLeft(2);
    T1->left->left->setRight(5);
    T1->setLeft(5);

    Node *T2 = new Node(2);
    T2->setRight(5);
    T2->setLeft(5);

    std::cout<<isSubtree(T1, T2);
}

/*
5 - 4 - 2 - 1
|		    |
4 - 1       8
|
2 - 5
|
5

2 - 5
|
5
*/
