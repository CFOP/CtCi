#include <bits/stdc++.h>

std::pair<uint8_t, uint8_t> nextNumber(uint8_t n){

	uint8_t firstOne;
	uint8_t i;
	for(i=n, firstOne=0; i%2==0; i/=2, firstOne++);

	uint8_t mask = ~(1<<firstOne);
	uint8_t small = n & mask;
	uint8_t large = n & mask;

	uint8_t lastZero = 0;
	uint8_t firstZero = 0;
	n >>= firstOne+1;

	for(i=firstOne+1; i<8; i++, n/=2){
		if(n%2==0){
			if(!firstZero)
				firstZero=i;
			lastZero=i;
		}
	}

	if(!lastZero){
		//throw error
	}

	small |= 1<<firstZero;
	large |= 1<<lastZero;

	return std::make_pair(small, large);
}

int main(){
    uint8_t n = 0b10110010;
    std::pair<uint8_t, uint8_t> next;
    next = nextNumber(n);
    std::bitset<8> small(next.first);
    std::bitset<8> large(next.second);
    std::cout<<small<<"\n";
    std::cout<<large<<"\n";
    return 0;
}
