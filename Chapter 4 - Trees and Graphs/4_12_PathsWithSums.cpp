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


int findSum(Node *root, int sum, std::unordered_map <int, int> &acum, int actualSum = 0){
	if(!root)
		return false;
	actualSum += root->data;
	int s = 0;
	if(acum.find(actualSum) == acum.end())
		acum[actualSum] = 0;
	acum[actualSum]++;
	if(acum.find(actualSum-sum) != acum.end())
		s = acum[actualSum-sum];
	s += findSum(root->left, sum, acum, actualSum);
	s += findSum(root->right, sum, acum, actualSum);
	acum[actualSum]--;
	if(!acum[actualSum])
        acum.erase(actualSum);
	return s;
}

int pathsWithSum(Node *root, int sum){
	std::unordered_map <int, int> acum;
	acum[0]=1;
	return findSum(root, sum, acum);
}

int main(){
    Node *root = new Node(2);

    root->setRight(5);
    root->setRight(10);
    root->right->setLeft(3);
    root->right->setLeft(1);
    root->setLeft(6);
    root->setLeft(4);

    std::cout<<pathsWithSum(root, 10);
    return 0;
}
/*
2 - 5 - 10
|   |
6   3 - 1
|
4
*/
