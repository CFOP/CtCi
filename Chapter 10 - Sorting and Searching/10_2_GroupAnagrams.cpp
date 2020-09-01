#include <bits/stdc++.h>
using namespace std;

vector <string> groupAnagrams(vector <string> word){
	unordered_map <string, vector<string>> group;
	for(string s : word){
		vector<int> count(260);
		for(char c : s)
			count[c]++;
		string key = "";
		for(int i = 0; i<260; i++)
            if(count[i])
                key += string(count[i], i);
		group[key].push_back(s);
	}

	vector<string> ans;
	for(auto v : group)
		for(string s: v.second)
			ans.push_back(s);

	return ans;
}

int main(){
    int n; cin>>n;
    vector <string> word;
    while(n--){
        string s; cin>>s;
        word.push_back(s);
    }

    word = groupAnagrams(word);

    cout<<"\n";
    for(string s : word)
        cout<<s<<"\n";

    return 0;
}
