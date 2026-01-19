#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &st, int mid){

    if(mid == 1){
        st.pop();
        return;
    }
    int val = st.top();
    st.pop();
    solve(st, mid-1);
    st.push(val);
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
        
    cout << endl;
    int mid = st.size() / 2 + 1;

    cout <<st.size()<< endl;
    solve(st, mid);
    while(!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;

        return 0;
}