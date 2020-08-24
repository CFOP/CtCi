#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

void generatePermutations(std::string s, std::vector<std::string> &p, int i = 0){
	if(i==s.size()){
        std::cout<<s<<"\n";
		p.push_back(s);
		return;
	}

    std::unordered_set<char> used;
	for(int j = i; j<s.size(); j++){
		std::swap(s[j], s[i]);
		if(used.find(s[i])==used.end())
            generatePermutations(s, p, i+1);
        used.insert(s[i]);
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

