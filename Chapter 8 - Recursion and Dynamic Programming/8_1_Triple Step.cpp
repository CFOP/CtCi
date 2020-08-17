#include <iostream>

int f(int n) { //Brute Force
	if(n == 0)
		return 1;
	if(n<0)
		return 0;
	return f(n-1) + f(n-2) + f(n-3);
}

unsigned long long tripleStep(int n){ //DP
	unsigned long long a = 1, b = 0, c = 0;
	while(n--){
		unsigned long long d = a+b+c;
		c = b;
		b = a;
		a = d;
	}
	return a;
}

int main(){
    std::cout<<f(8)<<"\n";
    std::cout<<tripleStep(8)<<"\n";
}
