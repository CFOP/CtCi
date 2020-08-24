#include <iostream>
#include <string>
#include <vector>

void generatePermutations(std::string s, std::vector<std::string> &p, int i = 0){
	if(i==s.size()-1){
        std::cout<<s<<"\n";
		p.push_back(s);
		return;
	}

	for(int j = i+1; j<s.size(); j++){
		std::swap(s[j], s[i]);
		generatePermutations(s, p, i+1);
		std::swap(s[j], s[i]);
	}
}

std::vector<std::string> PermutationsWithoutDups(std::string s){
	std::vector <std::string> p;
	generatePermutations(s, p);
	return p;
}

int main(){
    std::string s;
    std::cin>>s;
    PermutationsWithoutDups(s);
    return 0;
}
