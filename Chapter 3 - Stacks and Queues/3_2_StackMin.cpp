#include <iostream>
#include <stack>

class Stack : public std::stack<int>{
	private:
	std::stack <int> mini;

	public:

	Stack(){

	}

	int min(){
		return mini.top();
	}

	int push(int v){

		std::stack<int>::push(v);

		if(mini.empty())
				mini.push(v);
		else{
            if(v<=mini.top())
				mini.push(v);
		}
	}

	void pop(){
            if(top()==min())
                mini.pop();
			std::stack<int>::pop();
	}

};

int main(){
    Stack st;
    st.push(10);
    st.push(9);
    st.push(8);
    st.push(4);
    st.push(4);
    st.push(5);
    st.push(2);
    st.push(3);

    while(st.size()){
        std::cout<<st.top()<<" "<<st.min()<<"\n";
        st.pop();
    }
}
