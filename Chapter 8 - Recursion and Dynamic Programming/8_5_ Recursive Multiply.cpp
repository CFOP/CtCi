#include <bits/stdc++.h>

int mult(int a, int b){
    if(a==0)
        return 0;
    int ans = mult(a>>1, b) << 1;
    if(a%2)
        ans+=b;
    return ans;
}


int multiply(int a, int b){
    if(a>b) std::swap(a, b);
    return mult(a, b);
}

int main(){
    std::cout<<multiply(11, 231)<<"\n";
    return 0;
}
