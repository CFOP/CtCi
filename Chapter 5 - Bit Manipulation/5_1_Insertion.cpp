#include <bits/stdc++.h>
using namespace std;

uint32_t insertion(uint32_t N, uint32_t M, uint8_t i, uint8_t j){
	uint32_t mask = 1<<j;
	mask -= 1;
	mask &= ~(1<<i)-1;
	mask = ~mask;

	N &= mask;

	return N | M<<(i);
}

int main(){
    uint32_t ans = insertion(0b10000000000, 0b10011, 2, 6);
    std::cout<<std::bitset<32>(ans)<<"\n";
    return 0;
}
