#include <bits/stdc++.h>
using namespace std;

void delete_mid(stack<int> &st, int k){
	if(st.size() == k){
		st.pop();
		return;
	}
	int temp = st.top();
	st.pop();
	delete_mid(st, k);
	st.push(temp);
}

int main(){
	int n; cin >> n;
	stack <int>st;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		st.push(x);
	}
	int k = (st.size()/2)+1;
	delete_mid(st, k);
	while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
	cout << endl;
	return 0;
}