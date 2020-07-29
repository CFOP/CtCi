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
            right->setLeft(data);
        }
        else {
            right = new Node(data);
        }
    }
};

bool checkBST(Node *actual, int &min, int &max){
    if(!actual){
        min = INT_MIN;
        max = INT_MAX;
        return true;
    }

    int minRight, maxRight, minLeft, maxLeft;

    checkBST(actual->left, minLeft, maxLeft);
    checkBST(actual->right, minRight, maxRight);

    if(actual->left && actual->data < maxLeft)
        return false;
    if(actual->right && actual->data >= minRight)
        return false;

    max = min = actual->data;
    if(actual->right)
        max = maxRight;
    if(actual->left)
        min = minLeft;

    return true;
}

bool isBST(Node *root){
    int min,max;
    return checkBST(root, min, max);
}

int main(){
    Node *root = new Node(10);
    root->setRight(11);
    root->setRight(12);
    root->setLeft(8);
    root->setLeft(7);
    root->left->setRight(9);

    cout<<isBST(root);
    return 0;
}
