#include <bits/stdc++.h>

int pairwiseSwap(int n){
	return (n<<1 & 0b10101010101010101010101010101010) |
           (n>>1 & 0b01010101010101010101010101010101);
}

/*
int pairwiseSwap(int n){
	int r, mask, a;
	mask = 0b10101010101010101010101010101010;
	r = n<<1;
	r ^= n;
	mask &= r;
	mask = mask | (mask>>1);
	a = n&mask;
	a = (~a)&mask;
	n &= ~mask;
	n |= a;
	return n;
}
*/

int main(){
    int n = 123413;
    std::bitset<32> a(n);
    std::cout<<a<<"\n";
    a = std::bitset<32>(pairwiseSwap(n));
    std::cout<<a<<"\n";
    return 0;
}
