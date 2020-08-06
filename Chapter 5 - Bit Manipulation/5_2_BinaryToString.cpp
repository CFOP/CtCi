#include <bits/stdc++.h>

std::string bToString(double n){
	double p = 1;
	std::string ans = ".";
	if(n==1){
		ans = "1.0";
		n=0;
	}
	p/=2;
	for(int i=0; i<32 && n; i++, p/=2){
		if(p<=n){
			n-=p;
			ans+='1';
		}
		else ans+='0';
	}
	if(n)
		return "ERROR";
	return ans;
}

int main(){
    std::cout<<bToString(0.75);
    return 0;
}
