#include <bits/stdc++.h>
using namespace std;


void PV(vector<int> &a){
	for(int i =1; i<a.size(); i++){
		if(i%2){
			if(a[i] > a[i-1]){
			 swap(a[i], a[i-1]);
			}
		}
		else {
			if(a[i] < a[i-1]){
			 swap(a[i], a[i-1]);
			}
		}
	}
}

int main(){
    vector<int> a = {5, 8, 6, 2, 3, 4, 6};
    PV(a);
    for(int i : a)
        cout<<i<<" ";
    cout<<"\n";
}
