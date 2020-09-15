#include <bits/stdc++.h>
using namespace std;

//fail when a<1 or b<1 :c
int _max(int a, int b){
	return (int)(bool)(a/b) * a + (int)(bool)(b/a) * b  -  (a/b && b/a)*(int)(bool)(a/b)*a;
}

int main(){
    while(true){
        int a, b;
        cin>>a>>b;
        cout<<_max(a, b)<<"\n";
    }
    return 0;
}
