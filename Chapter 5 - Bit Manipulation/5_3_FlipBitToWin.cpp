#include <bits/stdc++.h>

bool getFirstBit(int n){
	return n & 1;
}

void deleteBit(int &n){
	n = n>>1;
}

uint8_t flipToWin(int n){
	uint8_t maxBits = 0;
	uint8_t lastSize = 0;
	uint8_t actualSize = 0;
	uint8_t zero = 0;

	for(uint8_t i = 0; i<=sizeof(int)*8; i++){
		if(i<sizeof(int)*8 && getFirstBit(n)){
			actualSize++;
		}
		else if(!actualSize)
			zero++;
		else {
			if(zero==1){
				maxBits = std::max(maxBits, (uint8_t)(actualSize+lastSize+1));
			}
			else if(!zero){
				maxBits = std::max(maxBits, (uint8_t)(actualSize+lastSize));
				zero++;
			}
			else {
				maxBits = std::max(maxBits, (uint8_t)(actualSize+1));
			}
			lastSize = actualSize;
			actualSize = 0;
		}
		deleteBit(n);
	}

	return maxBits;
}

int main(){
    std::cout<<(int)flipToWin((int)1775);
    return 0;
}
