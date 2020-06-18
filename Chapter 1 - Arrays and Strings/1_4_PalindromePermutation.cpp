#include <bits/stdc++.h>
using namespace std;

bool isPalindromePermutation(string word){

    bitset<'z'-'a'+1> c = 0;

    int realSize=0;
	for(int i=0; i<word.size(); i++){

        if(word[i]==' ')
            continue;

        if(word[i]>='A' && word[i]<='Z')
            c[word[i]-'A'] = !(c[word[i]-'A']);
		else
            c[word[i]-'a'] = !(c[word[i]-'a']);

        realSize++;

	}

    //cout<<realSize<<"\n";
	if(!(realSize%2))
        return c==0;
	else{
        return (bitset<26>(c.to_ulong()-1)&c) == 0;
	}

	return false;

}

int main(){
    cout<<isPalindromePermutation("Tact CoaZ")<<"\n";
    cout<<isPalindromePermutation("Tact Coa")<<"\n";
}
