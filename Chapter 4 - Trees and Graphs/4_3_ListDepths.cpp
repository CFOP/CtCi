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

void dfs(Node *actual, std::vector <std::forward_list<int>> &ans, int depth = 0){
	if(actual==nullptr)
		return;

	if(ans.size()==depth){
        std::forward_list<int> a;
		ans.push_back(a);
	}

	ans[depth].push_front(actual->data);

	dfs(actual->right, ans, depth+1);
	dfs(actual->left, ans, depth+1);

}


std::vector <std::forward_list<int>> listDepth(Node *root){
	std::vector <std::forward_list<int>> ans;
	dfs(root, ans);
	return ans;
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

    std::vector <std::forward_list<int>> ans;
    ans = listDepth(root);

    for(std::forward_list<int> l : ans){
        for(int i : l)
            std::cout<<i<<" ";
        std::cout<<"\n";
    }
}
