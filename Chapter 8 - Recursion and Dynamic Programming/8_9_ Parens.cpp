#include <iostream>

void parens(int n, int close = 0, std::string s = ""){
	if(!n){
		std::cout<<s;
		while(close--)
			std::cout<<')';
        std::cout<<"\n";
		return;
	}

	if(n){
		parens(n-1, close+1, s+'(');
	}

	if(close){
		parens(n, close-1, s+')');
	}

}

int main(){
    int n; std::cin>>n;
    parens(n);
    return 0;
}
