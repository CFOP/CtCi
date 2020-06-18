#include <iostream>
using namespace std;


void URLify(string &s, int realSize){

	int end=0;
	for(int i=0; i<realSize; i++){
		if(s[i]==' ')
			end++;
	}

	end=2*end+realSize;
	s = s.substr(0, end--);

	for(int i=realSize-1; end>i && i>=0; i--){
		if(s[i]!=' '){
			s[end--]=s[i];
		}
		else{
			s[end--]='0';
			s[end--]='2';
			s[end--]='%';
		}
	}
}

int main(){
    string s = "Mr John Smith        ";
    URLify(s, 13);
    cout<<s;
    return 0;
}
