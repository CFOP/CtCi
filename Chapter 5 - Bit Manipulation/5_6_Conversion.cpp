#include <bits/stdc++.h>
using namespace std;

int conversion(int a, int b){
    int s = 0;
    int actual = a^b;

    while(actual){
        s++;
        int mask = (actual-1)^actual;
        actual &=   ~mask;
    }

    return s;
}

int main(){
    std::cout<<conversion(29, 15);
    return 0;
}

