#include <iostream>
#include <vector>
using namespace std;

int find(vector<string> &array, string s){

	int left(0), right(array.size()-1);

	while(left<array.size() && array[left]=="")
		left++;
	while(right>=0 && array[right]=="")
		right--;
	right++;

	if(left >= right)
		return -1;

	while(left+1 < right){
		int m = (left+right)/2;
		int d = 0;
		while( (m+d < array.size() && array[m+d] == "") && (m-d >= 0 && array[m-d] == "") ){
			d++;
		}
        //cout<<m<<"\n";

		if(m-d >= 0 && array[m-d] == "")
			m = d+m;
		else m = m-d;

		if(m == left || m==right)
			right = left + 1;


		if(array[m]<=s)
			left = m;
		else right = m;
	}

	if(array[left]!=s)
		return -1;
	return left;

}

int main(){
    vector<string> array = {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
    cout<<find(array, "ball");
    return 0;
}
