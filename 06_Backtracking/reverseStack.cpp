#include <bits/stdc++.h>
using namespace std;


// void insert(stack<int> &s, int val){
//     if(s.empty()){
//         s.push(val);
//         return;
//     }
//     int temp = s.top();
//     s.pop();
//     insert(s, val);
//     s.push(temp);
//     cout << "Top Element: " << s.top() << endl;
// }
void reverse(stack<int> &st){
    if(st.size()==1){
        return;
    }
    int temp = st.top();
    cout << "Temp val: " << temp << endl;
    st.pop();
    reverse(st);
    // insert(st, temp);
    st.push(temp);
}

int main(){
    int n;
    cin >> n;
    stack<int> st;
    for (int i = 0;i<n;i++){
        int x;
        cin >> x;
        st.push(x);

    }
    // reverse(st);
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    return 0;
}