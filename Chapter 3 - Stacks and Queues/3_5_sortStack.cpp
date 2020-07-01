#include <bits/stdc++.h>

void sortStack(std::stack <int> &st){
	std::stack <int> reverse;
	for(int i=0; i<st.size(); i++){
        reverse.push(st.top());
        st.pop();
        while(st.size()){
            if(reverse.top()>st.top()){
                std::swap(reverse.top(), st.top());
            }
            reverse.push(st.top());
            st.pop();
        }

        while(reverse.size()){
            st.push(reverse.top());
            reverse.pop();
        }
	}

}

int main(){
    std::stack <int> st;
    st.push(1);
    st.push(2);
    st.push(6);
    st.push(5);
    st.push(5);
    st.push(7);
    st.push(4);
    st.push(2);

    sortStack(st);

    while(st.size()){
        std::cout<<st.top()<<"\n";
        st.pop();
    }

    return 0;
}
