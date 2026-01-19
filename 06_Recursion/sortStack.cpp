#include <bits/stdc++.h>
using namespace std;




void insert(stack<int> &st, int val){
    if(st.empty() || st.top()<=val){
        st.push(val);
        return;
    }
    int temp = st.top();
    st.pop();
    insert(st, val);
    st.push(temp);
}
void sort(stack<int> &st){
    if(st.size()==1)
        return;
    int temp = st.top();
    st.pop();
    sort(st);
    insert(st, temp);
}
int main(){
    int n;
    cin >> n;
    stack<int> st;
    for (int i = 0; i < n;i++){
        int x;
        cin >> x;
        st.push(x);
    }
    sort(st);
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}