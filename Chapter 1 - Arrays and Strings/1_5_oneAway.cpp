#include <bits/stdc++.h>
using namespace std;

bool isOneAway(string a, string b){
	if(a.size()<b.size())
		swap(a,b);
	if(a==b)
		return true;

	if(a.size()-b.size()>1)
		return false;

	for(int i=0; i<a.size()-1; i++){
		if(a[i]!=b[i]){
			if(a.size()==b.size()){
				a[i]=b[i];
				return a==b;
			}
			a.erase(i, 1);
			return a==b;
		}
	}

	return true;
}

int main(){
    cout<<isOneAway("aba", "abc");
    return 0;
}
