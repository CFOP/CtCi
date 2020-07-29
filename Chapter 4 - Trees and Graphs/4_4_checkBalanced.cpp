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
            right->setLeft(data);
        }
        else {
            right = new Node(data);
        }
    }
};

bool checkBalanced(Node *actual, int &height){
	if(!actual){
		height = 0;
		return true;
	}
	int leftHeight, rightHeight;
	if(!checkBalanced(actual->left, leftHeight))
		return false;
	if(!checkBalanced(actual->right, rightHeight))
		return false;

	if(abs(leftHeight-rightHeight) >  1)
		return false;

	height = std::max(leftHeight, rightHeight) + 1;
	return true;

}

bool isBalanced(Node *root){
	int firstHeight = 0;
	return checkBalanced(root, firstHeight);
}

/*
1 - 2 - 3
|
4 - 6
|
5
*/

int main(){
    Node *root = new Node(1);
    root->setRight(2);
    root->setRight(3);
    root->setLeft(4);
    root->setLeft(5);
    root->left->setRight(6);

    std::cout<<isBalanced(root);
    return 0;
}
