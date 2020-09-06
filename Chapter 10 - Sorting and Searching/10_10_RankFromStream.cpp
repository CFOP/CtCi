#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

ordered_multiset tr;

void track(int x){
	tr.insert(x);
}

//1 3 4 4 5 5 7 9 13
//13 9 7 5 5 4 4 3 1
int getRankOfNumber(int x){
	auto p = tr.lower_bound(x);
	if(p == tr.end())
		return 0;
	int pos = tr.order_of_key(*p);
	return pos-1;
}


/*
to call track
t [x]
to call getRank
g [x]
*/
int main(){
    tr.insert(5);
    tr.insert(1);
    tr.insert(4);
    tr.insert(4);
    tr.insert(5);
    tr.insert(9);
    tr.insert(7);
    tr.insert(13);
    tr.insert(3);
    while(true){
        char q; cin>>q;
        int x; cin>>x;
        if(q=='t')
            track(x);
        if(q=='g')
            cout<<getRankOfNumber(x)<<"#\n";
    }
}
