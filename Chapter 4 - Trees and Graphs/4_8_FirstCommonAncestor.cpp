#include <bits/stdc++.h>
using namespace std;

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


int findCA(Node *actual, const Node *a, const Node *b, Node *& ancestor){
	if(!actual)
		return 0;

	int equals = 0;
	if(a == actual)
		equals++;
	if(b == actual)
		equals++;

	if(equals == 1){
		if(findCA(actual->right, a, b, ancestor)){
			ancestor = actual;
			return 2;
		}
		if(findCA(actual->left, a, b, ancestor)){
			ancestor = actual;
			return 2;
		}
		return 1;
	}

	equals = findCA(actual->right, a, b, ancestor);
	if(equals == 2)
		return 2;

	if(equals == 1){
		if(findCA(actual->left, a, b, ancestor)){
			ancestor = actual;
			return 2;
		}
		return 1;
	}

	return equals + findCA(actual->left, a, b, ancestor);
}

Node* firsCommonAncestor(Node *root, Node *a, Node *b){
	Node *ancestor = nullptr;
	if(a==b)
		return a;
	if(findCA(root, a, b, ancestor) < 2)
		return nullptr;
	return ancestor;
}

int main(){
    Node *a = new Node(6);
    Node *b = new Node(7);
    Node *root = new Node(1);
    root->setRight(2);
    root->setRight(3);
    root->setLeft(4);
    root->setLeft(5);
    root->right->right->right = a;
    root->left->left = b;

    std::cout<<firsCommonAncestor(root, a, b)->data;
    return 0;
}
