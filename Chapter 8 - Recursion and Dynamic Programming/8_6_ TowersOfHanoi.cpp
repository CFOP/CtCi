#include <iostream>

void hanoi(int n, char a = 'a', char b = 'b', char c = 'c'){
	if(n == 1){
		std::cout<<a<<"->"<<c<<"\n";
		return;
	}
	hanoi(n-1, a, c, b);
	std::cout<<a<<"->"<<c<<"\n";
	hanoi(n-1, b, a, c);
}


int main(){
    hanoi(6);
    return 0;
}
