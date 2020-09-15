#include <bits/stdc++.h>
using namespace std;

int smallestDiferece(vector<int> a, vector<int> b){

     sort(a.begin(), a.end());
     sort(b.begin(), b.end());

     int ans = abs(a[0]-b[0]);

	 int i=0, j=0;
	 while(i<a.size() && j<b.size()){
        ans = min(ans, abs(a[i]-b[j]));
        if(a[i]<b[j]) i++;
        else j++;
	 }

	 return ans;
}


int main(){
    vector<int> a = {1, 3, 15, 11, 2};
    vector<int> b = {23, 127, 235, 19, 8};

    cout<<smallestDiferece(a, b);

    return 0;
}

/*
1 2 3 11 15
8 19 23 127 235

*/
