#include <bits/stdc++.h>

using namespace std;

int calculateSize(int n){
	int i=0;
	while(n){
		i++;
		n/=10;
	}
	return i;
}

string compression(string toCompress){
	if(!toCompress.size())
		return "";

	int newSize=1;
	char c=toCompress[0];
	int amount=1;
	for(int i=1; i<toCompress.size(); i++){
        //cout<<amount<<" "<<c<<" "<<toCompress[i]<<" "<<newSize<<"\n";
		if(toCompress[i]==c){
			amount++;
		}
		else{
			newSize+=calculateSize(amount)+1;
			amount=1;
			c=toCompress[i];
		}
	}
	newSize+=calculateSize(amount);

	//cout<<newSize<<"\n";

	if(newSize>=toCompress.size())
		return toCompress;

	string newString(newSize, ' ');

	c=toCompress[0];
	amount=1;
	newString[0]=toCompress[0];
	int s=1;
	for(int i=1; i<toCompress.size(); i++){
		if(toCompress[i]==c){
			amount++;
		}
		else{
			string add = to_string(amount);
			for(int j=0; j<add.size(); j++)
				newString[s++]=add[j];
			c=newString[s++]=toCompress[i];
			amount=1;
		}
	}
	{
		string add = to_string(amount);
		for(int j=0; j<add.size(); j++)
			newString[s++]=add[j];
	}
	return newString;
}

int main(){
    cout<<compression("aaaaaaaaaaddd");
    return 0;
}
