#include <iostream>
#include <vector>
using namespace std;

int coins(int n){
	vector<int> dp(n+1, 0);
	const vector<int> c= {25, 10, 5, 1};

	for(int i=0; i<c.size(); i++)
		if(n>=c[i])
			dp[c[i]]=1;

	for(int i =1; i<=n; i++)
		for(int coin : c)
			if(i>coin)
				dp[i] += dp[i-coin];

	return dp[n];
}

int main(){
    int n; cin>>n;
    cout<<coins(n)<<"\n";
}
